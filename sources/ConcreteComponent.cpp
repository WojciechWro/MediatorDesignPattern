#include "../include/BaseComponent.hpp"
#include "../include/ConcreteComponent.hpp"
#include "../interface/IMediator.hpp"

#include <iostream>

ConcreteComponent::ConcreteComponent():BaseComponent()
{
	std::cout << "ConcreteComponent Ctor!" << std::endl;
}

void ConcreteComponent::doComponentAstuff()
{
	std::cout << "Execute task A" << std::endl;
	this->mediator_->notify(this, "doTaskD");
}
