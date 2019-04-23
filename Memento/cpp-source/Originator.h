//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include "Memento.h"
namespace memento {

class Originator {
 public:
  void IncreaseLevel();
  void StartNewGame();

  Memento *Save(std::string save_name);
  void Restore(Memento *memento);

  // TODO(akhtyamovpavel) Refactor this function to other component, no stdout
  void ShowCurrentProgress();
 private:
  State state_ = {};
};

} // namespace memento



