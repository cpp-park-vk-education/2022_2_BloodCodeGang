#include <iostream>
#include "frontend/actionBus/actionbus.hpp"
#include "frontend/userinfo/iProfileUIModel.hpp"

class ProfileUIModel : public IProfileUIModel {
    private:
        IProfileUIModel *first_name;
        IProfileUIModel *age;
        IProfileUIModel *city;
        IProfileUIModel *description;
    public:
        void edit();
};