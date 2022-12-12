#include <iostream>
#include "frontend/actionBus/actionbus.hpp"
#include "frontend/authentification/IAuthUIModel.hpp"

class AuthUIModel : public IAuthUIModel {
    private:
        IAuthUIModel *login;
        IAuthUIModel *password;
        ActionBus *actions;
    public:
        void login();
}