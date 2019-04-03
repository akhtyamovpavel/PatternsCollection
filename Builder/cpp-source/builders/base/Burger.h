//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include <string>
#include <vector>

class Burger {
 public:
  explicit Burger(std::vector<std::string> components);
  friend std::ostream& operator << (std::ostream& ostream, const Burger& burger);
  std::string serialize() const;
 private:
  std::vector<std::string> components_;
};



