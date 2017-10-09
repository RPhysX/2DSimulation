#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "../Core/entity.h"
#include "../Renderer/renderer.h"

/*
*  =======================================================
*  texture.h
*  2DSimulation
*
*  Created by Primemaster on 04/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

/*
Bases: null
Definition: A class wich contains a SDL_Texture* object
Implementation: Create a Texture to be held in an Entity (eg. GUI)
*/
class Texture
{
public:
	Texture() = default;
	~Texture();
	friend void Entity::loadTexture(Renderer& rend);
	friend void Entity::setModel(const std::string& path);

	SDL_Texture* getTexture();
	void Texture::setPath(const std::string& path);

private:
	SDL_Texture* texture;
	std::string path;
};

