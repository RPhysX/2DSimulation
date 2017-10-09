#include "splaying.h"
#include <typeinfo>
#include <iostream>
#include <stdio.h>

void SPlaying::initialize(Application * app)
{
	std::cout << "State [" << typeid(*this).name() << "] initialized normally." << std::endl;

	/* Begin of Main state initialization zone */

	test[0] = common::loadEntity<Entity>("res/abc.png", masterRenderer);
	masterRenderer.push(test[0]);

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
	}
}

void SPlaying::update(Application * app)
{
	
}

void SPlaying::draw(Application * app)
{
	masterRenderer.draw();
}
