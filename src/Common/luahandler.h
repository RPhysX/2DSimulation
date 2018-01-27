#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <mutex>

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

#include <LuaBridge.h>

class LuaHandler
{
public:
	LuaHandler(const std::string& fileName);
	~LuaHandler();

	bool reload();

	template<typename T>
	inline T getVariable(const std::string& variableName)
	{
		if (!loaded)
			return NULL;
		mtx.lock();
		luabridge::LuaRef var = luabridge::getGlobal(L, variableName.c_str());
		mtx.unlock();
		if (var.isFunction())
		{
			std::cout << "[Lua] " << variableName << " is a function - please use getFunction() method." << std::endl;
		}
		if (var.isNil())
		{
			std::cout << "[Lua] Variable not found: " << variableName << std::endl;
			return NULL;
		}
		return var.cast<T>();
	}

	template<typename T>
	inline T getVariable(const std::string& tableName, const std::string& variableName)
	{
		if (!loaded)
			return NULL;
		mtx.lock();
		luabridge::LuaRef table = luabridge::getGlobal(L, tableName.c_str());
		mtx.unlock();
		if (table.isNil() || !table.isTable())
		{
			std::cout << "[Lua] Table not found: " << tableName << std::endl;
			return NULL;
		}

		mtx.lock();
		luabridge::LuaRef ret = table[variableName.c_str()];
		mtx.unlock();
		if (ret.isNil())
		{
			std::cout << "[Lua] Variable not found: " << variableName << std::endl;
			return NULL;
		}
		return ret.cast<T>();
	}

	template<typename T, typename... Args>
	inline std::function<T(Args ... args)> getFunction(const std::string& functionName)
	{
		if (!loaded)
			return NULL;
		mtx.lock();
		luabridge::LuaRef func = luabridge::getGlobal(L, functionName.c_str());
		mtx.unlock();
		if (!func.isFunction() || func.isNil())
		{
			std::cout << "[Lua] Function not found: " << functionName << std::endl;
			//return std::function<T(Args ... args)>();
		}
		std::function<T(Args ... args)> lambda = func;
		//return func(3, 4);
		return lambda;
	}

private:
	lua_State* L;
	std::string fileName;
	bool loaded = false;
	std::mutex mtx;
};

inline bool LuaHandler::reload()
{
	lua_State* newL;
	newL = luaL_newstate();
	if (luaL_dofile(newL, fileName.c_str()))
	{
		std::cout << "[Lua] Could not load script from file: " << fileName << std::endl;
		newL = nullptr;
		return false;
	}
	mtx.lock();
	L = newL;
	mtx.unlock();
	return true;
}
