#include "../include/BaseComponent.hpp"
#include "../include/SecondConcreteComponent.hpp"
#include "../interface/IMediator.hpp"

#include <iostream>

SecondConcreteComponent::SecondConcreteComponent() :BaseComponent()
{
	std::cout << "SecondConcreteComponent Ctor!" << std::endl;
}

void SecondConcreteComponent::doComponentBstuff()
{
	std::cout << "Execute task B" << std::endl;
	this->mediator_->notify(this, "doTaskB");
}
