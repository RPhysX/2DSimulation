#include "texture.h"
#include <SDL_image.h>
#include <exception>
#include "../Renderer/renderer.h"


void Texture::setPath(const std::string& path)
{
	this->path = path;
}


Texture::~Texture()
{
	SDL_DestroyTexture(texture);
}

SDL_Texture * Texture::getTexture()
{
	return texture;
}


