#include "../interface/Imediator.hpp"
#include "../include/ConcreteMediator.hpp"
#include "../include/BaseComponent.hpp"
#include "../include/ConcreteComponent.hpp"

#include <gtest/gtest.h>
#include <memory>

using testing::ExitedWithCode;

class ConcreteComponentTest : public ::testing::Test
{
protected: 
	ConcreteComponentTest() {};
	void SetUp() override {
		ptr1_ = new ConcreteComponent;
		ptr2_ = new SecondConcreteComponent;
		mediatorPtr_ = std::make_unique<ConcreteMediator>(ptr1_, ptr2_);
	};

	void TearDown() override {
		delete ptr1_;
		delete ptr2_;
	}

	ConcreteComponent *ptr1_;
	SecondConcreteComponent *ptr2_;
	std::unique_ptr<ConcreteMediator> mediatorPtr_;
};

TEST_F(ConcreteComponentTest, verifyDoComponentsMethods)
{
	testing::FLAGS_gtest_death_test_style = "threadsafe";

	ASSERT_NE(ptr1_, nullptr) << "nullptr detected";
	ASSERT_NE(ptr2_, nullptr) << "nullptr detected";
	ASSERT_NO_THROW(ptr1_->doComponentAstuff());
	ASSERT_NO_THROW(ptr2_->doComponentBstuff());
}

using ConcreteComponentDeathTest = ConcreteComponentTest;

TEST_F(ConcreteComponentDeathTest, performDeathTest)
{
	ptr1_ = nullptr;
	ASSERT_DEATH(ptr1_->doComponentAstuff(), "") << "Read access violation!";
}

TEST_F(ConcreteComponentDeathTest, verifyExitWithCode1)
{
	ptr1_ = nullptr;
	ASSERT_EXIT(ptr1_->doComponentAstuff(), testing::ExitedWithCode(1), "");
}

TEST_F(ConcreteComponentDeathTest, verifyDeathTestFailToDie)
{
	SCOPED_TRACE("Death Test Failed to Die");
	/* ptr1_ = nullptr;  test will fail to die, below assertion fails */
	ASSERT_EXIT(ptr1_->doComponentAstuff(), testing::ExitedWithCode(1), "");
}
