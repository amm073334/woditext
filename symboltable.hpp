#pragma once
#include <string>
#include <unordered_map>

class SymbolTable {
private:
	std::unordered_map<std::string, int32_t> table;
public:
	/**
	* Insert a variable into the symbol table.
	* @param name		Variable name.
	* @param cself_id	Cself id, from 0-99.
	* @return			True if successful, false if duplicate.
	*/
	bool insert(std::string name, int32_t cself_id) {
		std::pair<std::unordered_map<std::string, int32_t>::iterator, bool> res = table.insert(std::make_pair(name, cself_id));
		return res.second;
	}

	/**
	* Lookup a variable name.
	* @param name		Variable name.
	* @return			Cself id from 0-99 if found; -1 otherwise.
	*/
	int32_t lookup(std::string name) {
		std::unordered_map<std::string, int32_t>::iterator res = table.find(name);
		if (res == table.end()) {
			return -1;
		} else {
			return res->second;
		}
	}

	/**
	* Check if a variable exists in the current scope.
	* @param name		Variable name.
	* @return			Boolean denoting whether or not the variable was found.
	*/
	bool exists(std::string name) {
		return lookup(name) >= 0;
	}
};

class Symbol {

};