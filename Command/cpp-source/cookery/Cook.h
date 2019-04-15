//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#pragma once

#include <unordered_map>
#include <string>
#include <vector>

class Cook {
 public:
  void Prepare(std::string dish);
 private:
  std::unordered_map<std::string, std::vector<std::string> > recipes_ = {
      {"Borsh", {"Boil water", "Crop vegetables", "Mix"} },
      {"Solyanka", {"Boil water", "Add meat", "Add mix of meat"} }
  };
};



