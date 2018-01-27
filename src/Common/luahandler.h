#pragma once
#include <iostream>
#include <vector>
#include <string>
/*
*  =======================================================
*  luahandler.h
*  2DSimulation
*
*  Created by Primemaster on 05/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

/*
Bases: null
Definition: Lua programming language wrapper which takes default C<->Lua handling
Implementation: Use with Lua scripts
*/
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
	inline T get(const std::string& variableName)
	{
		//Requires implementation
	}

	bool lua_gettostack(const std::string& variableName)
	{
		//Requires implementation
	}

	// LUA GETTERS

	template<typename T>
	inline T lua_get(const std::string& variableName)
	{
		return 0;
	}
	template<typename T>
	inline T lua_getdefault()
	{
		return 0;
	}

private:
	lua_State* L;
};

template<>
inline std::string LuaHandler::lua_getdefault()
{
	return "null";
}

