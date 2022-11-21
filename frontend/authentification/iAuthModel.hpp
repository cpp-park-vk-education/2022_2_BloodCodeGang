#include <iostream>

class IAuthModel {
public:
    virtual void signIn() = 0;
    virtual void signOut() = 0;
};