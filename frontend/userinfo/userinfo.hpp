#include <iostream>

class UserInfo {
public:
    void create();
    void update();
private:
    std::string first_name;
    std::string last_name;
    std::string city;
    std::string age;
    std::string description;
};