#ifndef IMEDIATOR_HPP
#define IMEDIATOR_HPP

#include "../include/BaseComponent.hpp"

#include <string>

class BaseComponent;

class IMediator {
public:
	virtual void notify(BaseComponent *sender, std::string someInfo) const = 0;
};

#endif // IMEDIATOR_HPP
