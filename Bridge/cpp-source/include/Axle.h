//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#pragma once

class Axle {
 public:
  virtual void Accelerate(float speed) = 0;
  virtual void Brake(float speed) = 0;
  virtual void MoveLeft(float angle) = 0;
  virtual void MoveRight(float angle) = 0;
  virtual void MoveUp(float height) = 0;
  virtual void MoveDown(float height) = 0;
  virtual void Beep() = 0;
  virtual void PrintInfo() = 0;
};



