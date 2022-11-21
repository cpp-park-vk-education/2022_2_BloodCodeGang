#include <iostream>

struct Adress {
    std::string street;
    std::string city;
    std::string house_number;
};

struct Date {
    std::string day;
    std::string month;
    std::string year;
    std::string time;
};

struct Tag {
    size_t tag_id;
    std::string name;
};

struct UserInfo {
    size_t user_id;
    std::string name;
    std::string surname;
    int age;
};

struct EventInfo {
    size_t event_id;
    std::string title;
    std::string text;
    Adress adress;
    std::string contacts;
    Time time;
    bool is_private;
    bool is_offline;
    int capacity;
    std::vector<UserInfo> participants;
    UserInfo owner;
    std::vector<Tag> tags;
};