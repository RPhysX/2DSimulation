#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include "../App/application.h"
#include "../Core/entity.h"
/*
*  =======================================================
*  renderer.h
*  2DSimulation
*
*  Created by Primemaster on 04/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

class Texture;

/*
Bases: null
Definition: A class wich renders textures to the screen
Implementation: Create a renderer with properties to render textures
*/
class Renderer
{
public:
	Renderer();
	~Renderer();

	void push(Entity* entity);
	void update();
	void draw();

	SDL_Renderer* getInstance();

private:
	SDL_Renderer* renderer;
	std::vector<Entity*> entities;
};

