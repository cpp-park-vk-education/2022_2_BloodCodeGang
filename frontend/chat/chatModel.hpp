#include <iostream>
#include "frontend/userinfo/userinfo.hpp"
#include "frontend/chat/chatHistory.hpp"

class ChatModel : private UserInfo, private ChatHistory {
public:
    void getChatHistory(int recipient_id, int sender_id);
private:
    UserInfo recipient;
    UserInfo sender;
    ChatHistory history;
    std::string;
};