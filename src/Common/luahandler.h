#pragma once
#include <iostream>
#include <string>

extern "C" {
	#include <lua.h>
	#include <lauxlib.h>
	#include <lualib.h>
}

class LuaHandler
{
public:
	LuaHandler(const std::string& filename);
	~LuaHandler();

	void printError(const std::string& variableName, const std::string& reason);

	template<typename T>
	T get(const std::string& variableName)
	{
		if (!L) {
			printError(variableName, "Script is not loaded");
			return lua_getdefault<T>();
		}

		T result;
		if (lua_gettostack(variableName)) { // variable succesfully on top of stack
			result = lua_get<T>(variableName);
		}
		else {
			result = lua_getdefault<T>();
		}

		lua_pop(L, level + 1); // pop all existing elements from stack
		return result;
	}

	bool luagettostack(const std::string& variableName)
	{
		int level = 0;
		std::string var = "";
		for (unsigned int i = 0; i < variableName.size(); i++) {
			if (variableName.at(i) == '.') {
				if (level == 0) {
					lua_getglobal(L, var.c_str());
				}
				else {
					lua_getfield(L, -1, var.c_str());
				}

				if (lua_isnil(L, -1)) {
					printError(variableName, var + " is not defined");
					return false;
				}
				else {
					var = "";
					level++;
				}
			}
			else {
				var += variableName.at(i);
			}
		}
		if (level == 0) {
			lua_getglobal(L, var.c_str());
		}
		else {
			lua_getfield(L, -1, var.c_str());
		}
		if (lua_isnil(L, -1)) {
			printError(variableName, var + " is not defined");
			return false;
		}

		return true;
	}

	template<typename T>
	T lua_get(const std::string& variableName)
	{
		return 0;
	}

	template<typename T>
	T lua_getdefault(const std::string& variableName)
	{
		return 0;
	}

	/* Template specializations */

	template<>
	inline std::string lua_getdefault(const std::string& variableName) {
		return "null";
	}

	template <>
	inline bool lua_get(const std::string& variableName) {
		return (bool)lua_toboolean(L, -1);
	}

	template <>
	inline float lua_get(const std::string& variableName) {
		if (!lua_isnumber(L, -1)) {
			printError(variableName, "Not a number");
		}
		return (float)lua_tonumber(L, -1);
	}

	template <>
	inline int lua_get(const std::string& variableName) {
		if (!lua_isnumber(L, -1)) {
			printError(variableName, "Not a number");
		}
		return (int)lua_tonumber(L, -1);
	}

	template <>
	inline std::string lua_get(const std::string& variableName) {
		std::string s = "null";
		if (lua_isstring(L, -1)) {
			s = std::string(lua_tostring(L, -1));
		}
		else {
			printError(variableName, "Not a string");
		}
		return s;
	}

private:
	lua_State* L;
};

