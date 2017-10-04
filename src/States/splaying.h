#pragma once
#include "state.h"
/*
*  =======================================================
*  splaying.h
*  2DSimulation
*
*  Created by Primemaster on 03/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

/*
Bases: State [class] // Singleton [class]
Definition: Engine main playing class
Implementation: Interface main GUI
*/
class SPlaying : public State, public Singleton<SPlaying>
{
private:
	SPlaying() = default; //Private ctor
	~SPlaying() = default; //Private dtor
	friend class Singleton<SPlaying>;
	/* End of singleton declaration */

public:
	void initialize(Application * app);
	void cleanup();

	void pause();
	void resume();

	void handleEvents(Application * app);
	void update(Application * app);
	void draw(Application * app);
};

