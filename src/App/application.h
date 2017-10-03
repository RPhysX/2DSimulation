#pragma once
#include <stack>
#include "../Utils/singleton.h"
/*
*  =======================================================
*  application.h
*  2DSimulation
*
*  Created by Primemaster on 03/10/2017.
*  Copyright 2017 RPhysX. All rights reserved.
*
*  =======================================================
*/

class State;

/*
Bases: Singleton [class]
Definition: The single application handler class for the entire simulation
Implementation: State management and main loop organization
*/
class Application : public Singleton<Application>
{
private:
	Application(); //Private ctor
	~Application(); //Private dtor
	friend class Singleton<Application>;
	/* End of singleton declaration */

public:
	/* Management methods */
	
	void initialize();
	void cleanup();
	bool running();
	void quit();
		

	/* State handling functions */

	void pushState(State * state);
	void changeState(State * state);
	void popState();


	/* Main loop method calls */

	void handleEvents();
	void update();
	void draw();


private:
	std::stack<State*> states;
};

