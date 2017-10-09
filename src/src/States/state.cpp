#include "state.h"
#include "../App/application.h"

void State::changeState(Application * app, State * state)
{
	app->changeState(state);
}
