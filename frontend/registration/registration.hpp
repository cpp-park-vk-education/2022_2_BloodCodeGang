#include <iostream>
#include <string>
#include <./frontend/userinfo/userinfo.hpp>

class Registration : public UserInfo {
public:
    void create();
    void authentificate();

private:
    std::string new_first_name;
    std::string new_last_name;
    std::string new_city;
    std::string new_age;
    std::string new_description;
}