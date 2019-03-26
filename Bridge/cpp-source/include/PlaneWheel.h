//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#pragma once

#include "SteeringWheel.h"
class PlaneWheel: public SteeringWheel {
 public:
  explicit PlaneWheel(std::unique_ptr<Axle> axle);
  void PushWheel() override;
  void PullWheel() override;
  void PressGasPedal() override;
  void PressBreakPedal() override;
  void PressLeftButton() override;
  void PressRightButton() override;
  void MoveRightWheel(float angle) override;
  void MoveLeftWheel(float angle) override;
  void PressUpButton() override;
  void PressDownButton() override;
  void PrintInfo() override;

};



