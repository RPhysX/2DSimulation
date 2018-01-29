#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "../Utils/math.h"
/*
*  =======================================================
*  entity.h
*  2DSimulation
*
*  Created by Primemaster on 07/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

/*
Bases: null
Definition: Basic RPhysX engine entity class
Implementation: Base class for other entities instantiation
*/
class Texture;
class Renderer;

class Entity
{
public:
	Entity();
	~Entity();

	void loadTexture(Renderer& rend);
	void setModel(const std::string& path);
	Texture* getModel();
	const SDL_Rect * getSize() const;

	void setPosition(float x, float y) const;
	

private:
	SDL_Rect* size;
	Texture* model;

	math::Vector2f position;
	math::Vector2f velocity;
};

