#pragma once
#include "../Utils/singleton.h"
/*
*  =======================================================
*  state.h
*  2DSimulation
*
*  Created by Primemaster on 03/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

class Application;

/*
Bases: null
Definition: A class wich holds all the data for a engine state
Implementation: Create a state when a new element (eg. GUI, Screen) is created. Meant for implementation [virtual methods]
*/
class State
{
public:
	State() = default; //Public ctor
	~State() = default; //Public dtor

public:
	virtual void initialize(Application * app) = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents(Application * app) = 0;
	virtual void update(Application * app) = 0;
	virtual void draw(Application * app) = 0;

	void changeState(Application * app, State * state);
};

