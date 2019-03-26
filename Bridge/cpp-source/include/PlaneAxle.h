//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#pragma once

#include <Axle.h>

class PlaneAxle: public Axle {
 public:
  void Accelerate(float speed) override;
  void Brake(float speed) override;
  void MoveLeft(float angle) override;
  void MoveRight(float angle) override;
  void MoveUp(float height) override;
  void MoveDown(float height) override;
  void Beep() override;
  void PrintInfo() override;
 private:
  float angle_ = 0;
  float speed_ = 0;
  float rotate_angle_ = 0;
};



