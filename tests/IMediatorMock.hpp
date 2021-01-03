#include "../interface/IMediator.hpp"
#include "../include/BaseComponent.hpp"

#include <string>

#include <gmock/gmock.h>

class IMediatorMock : public IMediator {
public:
	MOCK_METHOD(void, notify, (BaseComponent *sender, std::string someInfo), (const, override));
};
