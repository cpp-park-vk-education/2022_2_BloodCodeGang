#include <iostream>
#include "frontend/chat/iChatModel.hpp"
#include "frontend/actionBus/actionbus.hpp"

class ChatUIModel : public IChatModel {
    private:
        IChatModel* recipient_id;
        IChatModel* sender_id;
        ActionBus* actions;
        std::string message;
    public:
        void sendMessage(int, string);
};