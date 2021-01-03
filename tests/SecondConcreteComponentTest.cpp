#include "../include/BaseComponent.hpp"
#include "../include/SecondConcreteComponent.hpp"
#include "../interface/Imediator.hpp"

#include <gtest/gtest.h>

class SecondConcreteComponentTest : public ::testing::Test
{
protected:
	SecondConcreteComponentTest() {};
	void SetUp() override {};
	void TearDown() override {}
};

TEST_F(SecondConcreteComponentTest, verifyClassMethods)
{
	// [TODO] verify class methods
}
