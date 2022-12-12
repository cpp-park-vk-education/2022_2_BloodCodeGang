#include <iostream>
#include "frontend/userinfo/userinfo.hpp"

class IProfileController : private UserInfo {
public:
    virtual UserInfo getProfile() = 0;
}