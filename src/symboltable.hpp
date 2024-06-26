#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
#include "doublestack.hpp"
#include "commonevent.hpp"

enum wod_type {
	t_error,
	t_dbunknown,
	t_void,
	t_int,

	// separate string literals from other strings (i.e. references) because 
	// they have to be handled differently in a command
	t_str,
	t_strlit
};

/**
* Symbols: Since common events are always globally scoped, hold their symbols in a separate table.
*/
struct VarSymbol {
	VarSymbol(std::string name, int32_t yobidasi, int32_t cself_index, wod_type type)
		: name(name), yobidasi(yobidasi), cself_index(cself_index), type(type) {}
	std::string name;
	int32_t yobidasi;
	int32_t cself_index;
	wod_type type;
};

struct CommonSymbol {
	static const int INTVAR_START = 10;
	static const int INTVAR_END = 98;
	static const int STRVAR_START = 5;
	static const int STRVAR_END = 8;

	CommonSymbol(std::string name, wod_type return_type, std::vector<VarSymbol*> params, CommonEvent* cev)
		: name(name), return_type(return_type), params(params), cev(cev) {}

	std::string name;
	wod_type return_type;
	std::vector<VarSymbol*> params;
	DoubleStack int_stack = DoubleStack(INTVAR_START, INTVAR_END);
	DoubleStack str_stack = DoubleStack(STRVAR_START, STRVAR_END);
	CommonEvent* cev;
};

/**
* Scope for variables in a common event.
*/
class VarScope {
private:
	typedef std::unordered_map<std::string, std::unique_ptr<VarSymbol>> VarScopeTable;

	VarScopeTable table;
	std::list<std::unique_ptr<VarScope>> children;
	VarScope* parent = nullptr;
	
	/**
	* Create a new scope from within this scope.
	* @return	Reference to the new scope.
	*/
	VarScope* create_child_scope() {
		std::unique_ptr<VarScope> new_scope = std::make_unique<VarScope>();
		new_scope->parent = this;
		children.push_back(std::move(new_scope));
		return children.back().get();
	}

	/**
	* Insert a variable into the scope.
	* @param name		Variable name.
	* @param symbol		Symbol.
	* @return			Pointer to symbol if successful, nullptr if failed.
	*/
	VarSymbol* insert(std::string name, std::unique_ptr<VarSymbol> symbol) {
		std::pair<VarScopeTable::iterator, bool> res = table.insert(std::make_pair(name, std::move(symbol)));
		return res.second ? res.first->second.get() : nullptr;
	}

	/**
	* Lookup a variable name.
	* @param name		Variable name.
	* @return			Pointer to the symbol.
	*/
	VarSymbol* lookup_var(std::string name) {
		VarScopeTable::iterator res = table.find(name);
		if (res != table.end()) return res->second.get();		// found; return pointer
		else if (!parent) return nullptr;						// not found; return nullptr
		else return parent->lookup_var(name);					// not found; search in parent scope
	}

	friend class SymbolTable;
};

/**
* Class to traverse the VarScope tree.
*/
class SymbolTable {
private:
	typedef std::unordered_map<std::string, std::unique_ptr<CommonSymbol>> CommonTable;
	
	CommonTable common_table;
	std::unique_ptr<VarScope> head;
	VarScope* curr_scope;

public:
	SymbolTable() {
		head = std::make_unique<VarScope>();
		curr_scope = head.get();
	}

	void open_scope() {
		curr_scope = curr_scope->create_child_scope();
	}

	void close_scope() {
		if (curr_scope->parent) curr_scope = curr_scope->parent;
		else std::cout << "debug: tried to close scope with no parent" << std::endl;
	}

	/**
	* Insert a variable into the symbol table.
	* @param symbol		Symbol.
	* @return			Pointer to symbol if successful, nullptr if duplicate.
	*/
	VarSymbol* insert(VarSymbol symbol) {
		return curr_scope->insert(symbol.name, std::make_unique<VarSymbol>(symbol));
	}

	/**
	* Insert a common event into the symbol table.
	* @param symbol		Common event prototype.
	* @return			Pointer to symbol if successful, nullptr if failed.
	*/
	CommonSymbol* insert(CommonSymbol symbol) {
		std::pair<CommonTable::iterator, bool> res = common_table.insert(
			std::make_pair(symbol.name, std::make_unique<CommonSymbol>(symbol)));
		return res.second ? res.first->second.get() : nullptr;
	}

	/**
	* Look up a variable name.
	* @param name		Variable name.
	* @return			Pointer to the associated symbol, or a null pointer if not found.
	*/
	VarSymbol* lookup_var(std::string name) {
		return curr_scope->lookup_var(name);
	}

	/**
	* Look up a common name.
	* @param name		Common event name.
	* @return			Pointer to the associated symbol, or a null pointer if not found.
	*/
	CommonSymbol* lookup_common(std::string name) {
		CommonTable::iterator res = common_table.find(name);
		if (res != common_table.end()) return res->second.get();		// found; return pointer
		else return nullptr;									// not found; return nullptr
	}
};