//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#pragma once

#include <string>

class Command {
 public:
  virtual void Execute() = 0;
  virtual uint16_t GetPrice() = 0;
  virtual std::string ToString() = 0;
};



