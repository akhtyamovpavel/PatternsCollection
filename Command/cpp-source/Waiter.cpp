//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#include "Waiter.h"
void Waiter::SetCommand(std::shared_ptr<Command> command) {
  command_ = command;
}

void Waiter::ExecuteCommand() {
  if (command_) {
    command_->Execute();
  }
}
