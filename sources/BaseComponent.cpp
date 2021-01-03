#include "../include/BaseComponent.hpp"
#include "../interface/IMediator.hpp"

#include <iostream>

BaseComponent::~BaseComponent(){};

BaseComponent::BaseComponent(IMediator* mediator): mediator_(mediator)
{
	std::cout << "Default BaseComponent Ctor" << std::endl;
}

void BaseComponent::setMediator(IMediator* mediator)
{
	this->mediator_ = mediator;
}
