//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#pragma once

#include <memory>
#include "commands/Command.h"
#include "cookery/Cook.h"

class Waiter {
 public:
  void SetCommand(std::shared_ptr<Command> command);
  void ExecuteCommand();
 private:
  std::shared_ptr<Command> command_;
  std::vector<Cook> cooks_;
};



