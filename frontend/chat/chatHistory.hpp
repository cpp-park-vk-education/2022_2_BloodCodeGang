#include <iostream>
#include <multimap>
#include "frontend/chat/chatModel.hpp"

class ChatHistory : private ChatModel {
public:
    void getMessages(int, string);
    void storeMessage(int, string);
private:
    std::multimap<int, string> history;
};