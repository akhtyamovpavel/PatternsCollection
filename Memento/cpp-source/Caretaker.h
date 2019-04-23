//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Memento.h"
#include "Originator.h"

namespace memento {

using StatePool = std::unordered_map<std::string, Memento*>;
using StateNames = std::unordered_set<std::string>;

class Caretaker {
 public:
  explicit Caretaker(Originator* originator);
  StateNames GetSaves();
  ~Caretaker();
  void Save(std::string save_name);
  void Load(std::string save_name);
 private:
  StatePool mementos_;
  Originator* originator_;

};

} // namespace memento

