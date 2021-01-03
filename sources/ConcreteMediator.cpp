#include "../include/BaseComponent.hpp"
#include "../include/ConcreteMediator.hpp"

#include <iostream>
#include <memory>
#include <string>

ConcreteMediator::ConcreteMediator(ConcreteComponent *compA, SecondConcreteComponent *compB): compA_(compA), compB_(compB)
{
	this->compA_->setMediator(this);
	this->compB_->setMediator(this);
}

void ConcreteMediator::notify(BaseComponent *sender, std::string someInfo) const
{
	if (someInfo == "doTaskA") {
		std::cout << "Mediator triggers:" << std::endl;
		this->compB_->doComponentBstuff();
	}
	else if (someInfo == "doTaskB") {
		this->compA_->doComponentAstuff();
	}
}
