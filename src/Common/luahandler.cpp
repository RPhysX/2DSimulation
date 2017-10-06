#include "luahandler.h"



LuaHandler::LuaHandler(const std::string& filename)
{
	L = luaL_newstate();
	if (luaL_loadfile(L, filename.c_str()) || lua_pcall(L, 0, 0, 0))
	{
		std::cout << "Error loading lua script from [" << filename << "]" << std::endl;
		L = NULL;
	}
}


LuaHandler::~LuaHandler()
{
	if (L) lua_close(L);
}

void LuaHandler::printError(const std::string & variableName, const std::string & reason)
{
	std::cout << "Error getting variable [" << variableName << "]. Reason: " << reason << std::endl;
}
