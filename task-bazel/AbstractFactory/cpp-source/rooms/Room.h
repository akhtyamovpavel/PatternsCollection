//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include <string>

class Room {
 public:
  virtual std::string GenerateBoss() const = 0;
  virtual std::string GenerateLoot() const = 0;
  virtual size_t chance() const = 0;
};
