#include "../include/BaseComponent.hpp"
#include "../include/ConcreteMediator.hpp"
#include "../include/ConcreteComponent.hpp"
#include "../include/SecondConcreteComponent.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class ConcreteMediatorTest : public testing::TestWithParam<std::string>
{
protected:
	void SetUp() override {
		ptr1_ = new ConcreteComponent;
		ptr2_ = new SecondConcreteComponent;
		mediatorPtr_ = std::make_unique<ConcreteMediator>(ptr1_, ptr2_);
	};
	void TearDown() override {}

	ConcreteComponent* ptr1_;
	SecondConcreteComponent* ptr2_;
	BaseComponent* sender;
	std::unique_ptr<ConcreteMediator> mediatorPtr_;
};

std::vector<std::string> params = {"doTaskA", "doTaskB", "doTaskX"};

TEST_P(ConcreteMediatorTest, verifyNotifyMethodParamsCall)
{
	ConcreteMediator obj1(ptr1_, ptr2_);
	obj1.notify(sender, GetParam());
}

INSTANTIATE_TEST_SUITE_P(VerifyParams, ConcreteMediatorTest, testing::ValuesIn(params));
