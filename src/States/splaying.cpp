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

	atm[0] = common::loadEntity<Atom>("res/PaidaNanofisica.png", masterRenderer);
	masterRenderer.push(atm[0]);


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
			switch (e.key.keysym.sym) {
			case SDLK_UP: 
				atm[0]->setPosition(0.0f, 0.0f);
				break;
			}
		}
	}
}

void SPlaying::update(Application * app)
{
	static float a, b = 0.0f;
	atm[0]->setPosition(a+=0.01f, b+=0.0075f);

}

void SPlaying::draw(Application * app)
{
	masterRenderer.draw();
}
