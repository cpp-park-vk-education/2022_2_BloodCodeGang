#include <iostream>
#include "frontend/userinfo/userinfo.hpp"

class ProfileController : private UserInfo {
public:
    UserInfo getInfo();
private:
    UserInfo user;
}