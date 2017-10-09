#pragma once
#include <iostream>
#include "../Core/entity.h"
/*
*  =======================================================
*  common.h
*  2DSimulation
*
*  Created by Primemaster on 09/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

/*
Bases: null
Definition: Helper functions
Implementation: Use as code shrinkers (e.g. wrappers)
*/
namespace common
{
	template<typename Spec>
	inline Entity * loadEntity(const std::string& texturedModel, Renderer& renderer)
	{
		Entity* returned = new Spec();
		returned->setModel(texturedModel);
		try
		{
			returned->loadTexture(renderer);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Entity [" << typeid(*returned).name() << "] initialized normally." << std::endl;
		return returned;
	}
}