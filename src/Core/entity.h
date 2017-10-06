#pragma once
#include <SDL.h>
#include <iostream>
#include <string>

class Texture;
class Renderer;

class Entity
{
public:
	Entity();
	~Entity();

	void loadTexture(Texture& tex, Renderer& rend);
	Texture* getModel();

private:
	Texture* model;
};

