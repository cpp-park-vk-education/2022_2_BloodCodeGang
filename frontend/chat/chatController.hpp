#include <iostream>
#include "frontend/chat/chatModel.hpp"

class ChatController : private ChatModel {
public:
    ChatModel sendMessage();
};