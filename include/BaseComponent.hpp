#ifndef BASECOMPONENT_HPP
#define BASECOMPONENT_HPP

class IMediator;

class BaseComponent 
{
public:
	virtual ~BaseComponent();
	BaseComponent(IMediator *mediator = nullptr);
	
	void setMediator(IMediator *mediator);

protected:
	IMediator *mediator_;
};

#endif // BASECOMPONENT_HPP
