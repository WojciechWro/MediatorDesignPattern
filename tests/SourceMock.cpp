#include "IMediatorMock.hpp"
#include "../include/BaseComponent.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::NiceMock;

TEST(IMediatorMock, veriyNotifyMethod)
{
	IMediatorMock mediator_mock;
	BaseComponent* sender = nullptr;
	std::string someInfo = "text1";

	EXPECT_THAT(someInfo, HasSubstr("text")) << "HasSubstring criteria not met";
	EXPECT_THAT(someInfo, MatchesRegex("\\w*\\d*"));

	EXPECT_CALL(mediator_mock, notify(_,_))
		.Times(AnyNumber());
	EXPECT_CALL(mediator_mock, notify(sender, HasSubstr("text")))
		.Times(AtLeast(1));

	mediator_mock.notify(sender, someInfo);
}

TEST(IMediatorMock, checkNiceMockFunctionality)
{
	NiceMock<IMediatorMock> mediator_nice_mock;

	BaseComponent* sender = nullptr;
	std::string someInfo;

	mediator_nice_mock.notify(sender, someInfo);
}
