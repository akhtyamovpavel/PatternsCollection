//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#pragma once

#include "Command.h"
#include "../cookery/Cook.h"

#include <vector>
#include <string>
#include <memory>

class CreateSoupCommand : public Command {
 public:
  void Execute() override;
  std::string ToString() override;
  CreateSoupCommand(std::shared_ptr<Cook> cook, std::string dish);
 private:
  uint16_t GetPrice() override;
 private:
  std::string dish_;
  std::shared_ptr<Cook> cook_;
};



