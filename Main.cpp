#include "../interface/IMediator.hpp"
#include "../include/ConcreteMediator.hpp"
#include "../include/BaseComponent.hpp"
#include "../include/ConcreteComponent.hpp"

#include <exception>
#include <iostream>
#include <memory>

#include <gtest/gtest.h>

void ClientExecutes()
{
	try 
	{
		ConcreteComponent* componentPtrA = new ConcreteComponent;
		SecondConcreteComponent* componentPtrB = new SecondConcreteComponent;
		std::unique_ptr<ConcreteMediator> mediatorPtr = std::make_unique<ConcreteMediator>(componentPtrA, componentPtrB);

		componentPtrB->doComponentBstuff();
		componentPtrA->doComponentAstuff();

		delete componentPtrA;
		delete componentPtrB;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Thrown exception in main thread" << e.what() << std::endl;
	}
}

int main(int argc, char** argv)
{
	std::cout << "Build by CMake program works!" << std::endl;
	ClientExecutes();

	::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}
