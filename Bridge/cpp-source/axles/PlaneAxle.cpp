//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#include <PlaneAxle.h>
#include <iostream>


void PlaneAxle::Accelerate(float speed) {
  speed_ += speed;
}

void PlaneAxle::Brake(float speed) {
  speed_ -= speed;
  if (speed_ < 0) {
    speed_ = 0;
  }
}

void PlaneAxle::MoveLeft(float angle) {
  rotate_angle_ += angle;
}

void PlaneAxle::MoveRight(float angle) {
  rotate_angle_ -= angle;
}

void PlaneAxle::MoveUp(float height) {
  angle_ += height;
}

void PlaneAxle::MoveDown(float height) {
  angle_ -= height;
  if (angle_ < 0) {
    angle_ = 0;
  }
}

void PlaneAxle::Beep() {

}

void PlaneAxle::PrintInfo() {
  std::cout << "Type: Plane" << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Angle: " << angle_ << std::endl;
  std::cout << "Rotate angle: " << rotate_angle_ << std::endl;
}
