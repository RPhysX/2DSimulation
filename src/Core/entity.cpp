#include "entity.h"
#include "../Common/texture.h"
#include "../Renderer/renderer.h"
#include <SDL_image.h>
#include <exception>



Entity::Entity() : size(new SDL_Rect()), model(new Texture())
{
}


Entity::~Entity()
{
}

void Entity::loadTexture(Renderer& rend)
{
	SDL_Surface* img = IMG_Load(model->path.c_str());
	if (img == NULL)
	{
		throw std::exception("Failed to load image from path.");
	}
	else
	{
		size->w = img->w;
		size->h = img->h;
		size->x = 0;
		size->y = 0;
		model->texture = SDL_CreateTextureFromSurface(rend.getInstance(), img);
		SDL_FreeSurface(img);
	}
}

void Entity::setModel(const std::string & path)
{
	model->path = path;
}

Texture * Entity::getModel()
{
	return model;
}

const SDL_Rect * Entity::getSize() const
{
	return size;
}
