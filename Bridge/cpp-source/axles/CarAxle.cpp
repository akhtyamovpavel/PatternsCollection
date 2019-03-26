//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#include "CarAxle.h"

#include <iostream>

void CarAxle::Accelerate(float speed) {
  this->speed += 0.1;
}

void CarAxle::Brake(float speed) {
  this->speed -= 0.1;
  if (this->speed < 0) {
    this->speed = 0;
  }
}

void CarAxle::MoveLeft(float angle) {
  this->move_angle += 0.1;
}

void CarAxle::MoveRight(float angle) {
  this->move_angle -= 0.1;
}

void CarAxle::MoveUp(float height) {}

void CarAxle::MoveDown(float height) {}

void CarAxle::Beep() {
  std::cout << "Beep" << std::endl;
}

void CarAxle::PrintInfo() {
  std::cout << "Type: Car" << std::endl;
  std::cout << "Speed: " << speed << std::endl;
  std::cout << "Angle: " << move_angle << std::endl;
}
