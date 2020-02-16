//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include "states/State.h"

#include <memory>

using StatePointer = std::unique_ptr<State>;


enum Direction {
  TO_GREEN,
  TO_RED
};

class TrafficLight {
 public:
  TrafficLight();
  void SetState(StatePointer state);
  Direction GetDirection();
  void SetDirection(Direction direction);
  void ChangeColor();
  // TODO(akhtyamovpavel) Refactor this state
  void PrintState();
 private:
  StatePointer state_;
  Direction direction_;
};



