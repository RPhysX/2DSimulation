#include "splaying.h"
#include <typeinfo>
#include <iostream>

void SPlaying::initialize(Application * app)
{
	std::cout << "State [" << typeid(*this).name() << "] initialized normally." << std::endl;
	tex[0].setPath("res/abc.png");
	try
	{
		test[0].loadTexture(tex[0], masterRenderer);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	masterRenderer.push(&test[0]);
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
			printf("Nice try!\n");
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
