#pragma once
#include "../Utils/singleton.h"
/*
*  =======================================================
*  state.h
*  2DSimulation
*
*  Created by Primemaster on 03/10/2017.
*  Copyright 2017 RPhysX. All rights reserved.
*
*  =======================================================
*/

class Application;

/*
Bases: null
Definition: A class wich holds all the data for a engine state
Implementation: Create a state when a new elemnt (eg. GUI, Screen) is created. Meant for implementation [virtual methods]
*/
class State : public Singleton<State>
{
private:
	State(); //Private ctor
	~State(); //Private dtor
	friend class Singleton<State>;
	/* End of singleton declaration */

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

