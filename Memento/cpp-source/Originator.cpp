//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include <iostream>
#include "Originator.h"
#include "PasswordMemento.h"

namespace memento {

void Originator::IncreaseLevel() {
  ++state_.level;
  state_.progress += DEFAULT_PROGRESS_LEVEL;
}

void Originator::StartNewGame() {
  state_ = {
      .place = "Start",
      .level = 1,
      .progress = 0,
      .save_name = ""
  };
}

Memento * Originator::Save(std::string save_name) {
  return new PasswordMemento(state_);
}

void Originator::Restore(Memento *memento) {
  state_ = memento->GetState();
}

void Originator::ShowCurrentProgress() {
  std::cout << "Place: " << state_.place << std::endl;
  std::cout << "Level: " << state_.level << std::endl;
  // https://stackoverflow.com/questions/19562103/uint8-t-cant-be-printed-with-cout
  std::cout << "Progress: " << unsigned(state_.progress) << std::endl;
}

} // namespace memento
