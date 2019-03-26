//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#pragma once

#include <memory>
#include <Axle.h>

class SteeringWheel {
 public:
  explicit SteeringWheel(std::unique_ptr<Axle> axle);
  virtual void PushWheel() = 0;
  virtual void PullWheel() = 0;
  virtual void PressGasPedal() = 0;
  virtual void PressBreakPedal() = 0;
  virtual void PressLeftButton() = 0;
  virtual void PressRightButton() = 0;
  virtual void MoveRightWheel(float angle) = 0;
  virtual void MoveLeftWheel(float angle) = 0;
  virtual void PressUpButton() = 0;
  virtual void PressDownButton() = 0;
  virtual void PrintInfo() = 0;
 protected:
  std::unique_ptr<Axle> axle_;
};



