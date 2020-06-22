//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#pragma once

#include <memory>
#include "Command.h"
#include "../cookery/Barman.h"

class CreateCocktailCommand : public Command {
 public:
  void Execute() override;
  uint16_t GetPrice() override;
  std::string ToString() override;
  CreateCocktailCommand(std::shared_ptr<Barman> barman, std::string dish);
 private:
  std::string dish_;
  std::shared_ptr<Barman> barman_;
};



