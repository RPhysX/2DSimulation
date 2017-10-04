#include "splaying.h"
#include <typeinfo>

void SPlaying::initialize(Application * app)
{
	std::cout << "State [" << typeid(*this).name() << "] initialized normally." << std::endl;
}

void SPlaying::cleanup()
{

}

void SPlaying::pause()
{

}

void SPlaying::resume()
{

}

void SPlaying::handleEvents(Application * app)
{
	
}

void SPlaying::update(Application * app)
{
	
}

void SPlaying::draw(Application * app)
{
	
}
