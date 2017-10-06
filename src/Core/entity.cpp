#include "entity.h"
#include "../Common/texture.h"
#include "../Renderer/renderer.h"
#include <SDL_image.h>
#include <exception>



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::loadTexture(Texture & tex, Renderer& rend)
{
	SDL_Surface* img = IMG_Load(tex.path.c_str());
	if (img == NULL)
	{
		throw std::exception("Failed to load image from path.");
	}
	else
	{
		tex.texture = SDL_CreateTextureFromSurface(rend.getInstance(), img);
		SDL_FreeSurface(img);
		model = &tex;
	}
}

Texture * Entity::getModel()
{
	return model;
}
