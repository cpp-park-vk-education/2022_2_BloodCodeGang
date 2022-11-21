#include <iostream>
#include "frontend/chat/chatModel.hpp"

class IChatModel {
public:
    virtual void getChatHistory(int recipient_id, int sender_id) = 0;
};