#include <iostream>
#include <thread>
#include "App\application.h"
#include "States\state.h"
#include "States\splaying.h"
#include "Common\luahandler.h"

/*
*  2DSimulation
*  Copyright(C) 2017 RPhysX
*
*  This program is free software : you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.If not, see <http://www.gnu.org/licenses/>
*/

void reloadLua(LuaHandler* l)
{
	while (true)
	{
		if (getchar() == 'r')
		{
			l->reload();
			continue;
		}
		break;
	}
}

int main(int argc, char** argv)
{
	LuaHandler* l = new LuaHandler("src/test.lua");
	std::thread t0(reloadLua, l);
	auto sum = l->getFunction<int, int, int>("sum");
	auto res = sum(3, 4);
	auto post = l->getVariable<int>("post");
	auto tableV1 = l->getVariable<int>("table1", "v1");

	std::cout << "Result: " << res << std::endl;
	std::cout << "Post val: " << post << std::endl;
	std::cout << "V1: " << tableV1 << std::endl;


	Application* app = Application::Instance();
	app->initialize("RPhysX 1.0");
	app->pushState(SPlaying::Instance());
	while (app->running())
	{
		auto sum = l->getFunction<float, int, int>("sum");
		auto res = sum(3, 4);
		//std::cout << "Func: " << res << std::endl;
		app->handleEvents();
		app->update();
		app->draw();
	}

	t0.join();
	return 0;
}
