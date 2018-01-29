#include "luahandler.h"
#include "../Core/entity.h"

LuaHandler::LuaHandler(const std::string & fileName)
{
	this->fileName = fileName;
	L = luaL_newstate();

	luabridge::getGlobalNamespace(L).addFunction("printMessage", Entity::setPosition);

	if (luaL_dofile(L, fileName.c_str()))
	{
		std::cout << "[Lua] Could not load script from file: " << fileName << std::endl;
		L = nullptr;
	}
	loaded = true;
}

LuaHandler::~LuaHandler()
{

}

