//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "TrafficLight.h"
#include "states/Red.h"

#include <iostream>

TrafficLight::TrafficLight(): direction_(TO_GREEN) {
  state_ = std::make_unique<Red>();
}

void TrafficLight::SetState(StatePointer state) {
  state_ = std::move(state);
}

Direction TrafficLight::GetDirection() {
  return direction_;
}

void TrafficLight::SetDirection(Direction direction) {
  direction_ = direction;
}

void TrafficLight::ChangeColor() {
  state_->Switch(this);
}

void TrafficLight::PrintState() {
  std::cout << "State" << std::endl;
  std::cout << "Direction: " << direction_ << std::endl;
  std::cout << "Color: " << state_->GetStringState() << std::endl;
}
