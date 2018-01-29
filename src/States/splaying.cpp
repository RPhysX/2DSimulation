#include "splaying.h"
#include <typeinfo>
#include <iostream>
#include <stdio.h>

void SPlaying::initialize(Application * app)
{
	std::cout << "State [" << typeid(*this).name() << "] initialized normally." << std::endl;

	scriptHandler = new LuaHandler("src/Scripts/test.lua");

	/* Begin of Main state initialization zone */
	
	entities.setRenderer(masterRenderer);
	unsigned int ENTITY_SIZE = scriptHandler->getVariable<unsigned int>("ENTITY_SIZE");
	for (unsigned int i = 0; i < ENTITY_SIZE; i++)
	{
		entities.pushValue(scriptHandler->getVariable<std::string>("atom", "texture"), scriptHandler->getVariable<std::string>("atom", "name"));
	}

	entities.loadValues();


	/* End of Main state initialization zone */
}

void SPlaying::cleanup()
{

}

void SPlaying::pause()
{

}

void SPlaying::resume()
{

}

void SPlaying::handleEvents(Application * app)
{
	static SDL_Event e;
	if (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			app->quit();
		}
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) 
			{
				case SDLK_UP: 
					test[1]->setPosition(0.0f, 0.0f);
					break;

				case SDLK_r:
					scriptHandler->reload();
					break;
			}
		}
	}
}

void SPlaying::update(Application * app)
{
	static float a, b = 0;
	test[1]->setPosition(a+=0.01f, b+=0.0075f);
	func(*test[0]);
}

void SPlaying::draw(Application * app)
{
	masterRenderer.draw();
}
