#pragma once
#include <string>
#include <unordered_map>

enum var_type {
	t_void,
	t_int,
	t_str
};

struct VarSymbol {
	VarSymbol(std::string name, int32_t yobidasi, var_type type)
		: name(name), yobidasi(yobidasi), type(type) {}
	std::string name = "";
	int32_t yobidasi = 0;
	var_type type = t_int;
};

class Scope {
private:
	typedef std::unordered_map<std::string, std::unique_ptr<VarSymbol>> ScopeTable;

	ScopeTable table;
	std::list<std::unique_ptr<Scope>> children;
	Scope* parent = NULL;
public:
	/**
	* Create a new scope from within this scope.
	* @return	Reference to the new scope.
	*/
	Scope* create_child_scope() {
		std::unique_ptr<Scope> new_scope = std::make_unique<Scope>();
		new_scope->parent = this;
		children.push_back(std::move(new_scope));
		return children.back().get();
	}

	/**
	* Insert a variable into the scope.
	* @param name		Variable name.
	* @param symbol		Symbol.
	* @return			True if successful, false if failed.
	*/
	bool insert(std::string name, std::unique_ptr<VarSymbol> symbol) {
		std::pair<ScopeTable::iterator, bool> res = table.insert(std::make_pair(name, std::move(symbol)));
		return res.second;
	}

	/**
	* Lookup a variable name.
	* @param name		Variable name.
	* @return			Pointer to the symbol.
	*/
	VarSymbol* lookup(std::string name) {
		ScopeTable::iterator res = table.find(name);
		if (res != table.end()) return res->second.get();	// found; return pointer
		else if (!parent) return NULL;						// not found; return NULL
		else return parent->lookup(name);					// not found; search in parent scope
	}

};

/**
* Class to traverse the Scope tree.
*/
class SymbolTable {
private:
	std::unique_ptr<Scope> head;
	Scope* curr_scope;
	std::unordered_map<std::string, int32_t> table;
public:
	SymbolTable() {
		head = std::make_unique<Scope>();
		curr_scope = head.get();
	}

	/**
	* Insert a variable into the symbol table.
	* @param symbol		Symbol.
	* @return			True if successful, false if duplicate.
	*/
	bool insert(VarSymbol symbol) {
		return curr_scope->insert(symbol.name, std::make_unique<VarSymbol>(symbol));
	}

	/**
	* Look up a variable name.
	* @param name		Variable name.
	* @return			Pointer to the associated symbol, or NULL if not found.
	*/
	VarSymbol* lookup(std::string name) {
		return curr_scope->lookup(name);
	}

};