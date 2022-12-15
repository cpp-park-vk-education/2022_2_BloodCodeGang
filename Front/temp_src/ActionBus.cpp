//
// Created by Алексей on 21.11.2022.
//

#include "../temp_include/ActionBus.h"

void ActionBus::subscribe(IObservable *sub, int type) {}
void ActionBus::dispatch(int type, const Action& action) {}
void ActionBus::unsubscribe(IObservable *sub_to_delete, int type) {}