#include "renderer.h"
#include "../Common/texture.h"
#include <SDL_image.h>


Renderer::Renderer()
{
	renderer = SDL_CreateRenderer(Application::Instance()->rWindow(), -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "Failed to initialize SDL2 renderer. Error code: " << SDL_GetError() << std::endl;
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::push(Entity * entity)
{
	entities.push_back(entity);
}

void Renderer::pushV(Entity** entities, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		this->entities.push_back(entities[i]);
	}
}

void Renderer::update()
{
}

void Renderer::draw()
{
	SDL_RenderClear(renderer);

	for(auto* ent : entities)
		SDL_RenderCopy(renderer, ent->getModel()->getTexture(), NULL, ent->getSize());

	SDL_RenderPresent(renderer);
}

SDL_Renderer * Renderer::getInstance()
{
	return renderer;
}
