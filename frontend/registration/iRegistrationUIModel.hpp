#include <iostream>
#include "frontend/actionBus/actionbus.hpp"
#include "frontend/registration/iRegistrationUIModel.hpp"

class IRegistrationUIModel : public IRegistrationUIModel {
    private:
        IRegistrationUIModel *new_first_name;
        IRegistrationUIModel *new_last_name;
        IRegistrationUIMode *new_city;
        IRegistrationUIModel *new_age;
        IRegistrationUIModel *description;
        IRegistrationUIModel *password;
        IRegistrationUIModel *username;
        ActionBus *actions;
    public:
        void create();
}