#include <iostream>
#include "frontend/userinfo/userinfo.hpp"

class ProfileController : private userinfo {
public:
    userinfo getInfo();
};