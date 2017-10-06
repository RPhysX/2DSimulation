#include "application.h"
#include "../States/state.h"
#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


Application::~Application()
{
	SDL_DestroyWindow(window);
	window = NULL;
}

void Application::initialize(const char* title)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialize SDL2. Error code: " << SDL_GetError() << std::endl;
	}
	else
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "Failed to initialize SDL2 window. Error code: " << SDL_GetError() << std::endl;
		}
		else
		{
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!IMG_Init(imgFlags) & imgFlags)
				{
					std::cout << "Failed to initialize SDL_image. Error code: " << IMG_GetError() << std::endl;
				}
			}
		}
}

void Application::cleanup()
{
	//CleanUp states
	while (!states.empty())
	{
		states.top()->cleanup();
		states.pop();
	}
}

bool Application::running()
{
	return false;
}

void Application::quit()
{
}

void Application::pushState(State * state)
{
	if (!states.empty())
	{
		states.top()->pause();
	}

	states.push(state);

	state->initialize(Application::Instance());
}

void Application::changeState(State * state)
{
	if (!states.empty())
	{
		states.top()->cleanup();
		states.pop();
	}

	states.push(state);
	states.top()->initialize(Application::Instance());
}

void Application::popState()
{
	if (!states.empty())
	{
		states.top()->cleanup();
		states.pop();
	}

	if (!states.empty())
	{
		states.top()->resume();
	}
}

void Application::handleEvents()
{
	states.top()->handleEvents(Application::Instance());
}

void Application::update()
{
	states.top()->update(Application::Instance());
}

void Application::draw()
{
	states.top()->draw(Application::Instance());
}

SDL_Window * Application::rWindow()
{
	return window;
}
