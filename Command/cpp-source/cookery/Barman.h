//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Barman {
 public:
  void Prepare(std::string cocktail);

  std::unordered_map<std::string, std::vector<std::string> > recipes_ = {
      {"Strawberry", {"Add strawberry", "Add milk"} },
      {"Chokolate", {"Add chokolate", "Add milk", "Add pour"} }
  };
};



