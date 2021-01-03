#ifndef CONCRETEMEDIATOR_HPP
#define CONCRETEMEDIATOR_HPP

#include "../include/BaseComponent.hpp"
#include "../include/ConcreteComponent.hpp"
#include "../include/SecondConcreteComponent.hpp"
#include "../interface/IMediator.hpp"

#include <memory>
#include <string>

class IMediator;

class ConcreteMediator : public IMediator
{
public:
	ConcreteMediator(ConcreteComponent *compA, SecondConcreteComponent* compB);
	void notify(BaseComponent *sender, std::string someInfo) const override;

private:
	ConcreteComponent *compA_;
	SecondConcreteComponent *compB_;
};

#endif // CONCRETEMEDIATOR_HPP
