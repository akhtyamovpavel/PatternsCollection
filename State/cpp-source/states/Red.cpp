//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "Red.h"
#include "Yellow.h"
#include "../TrafficLight.h"

void Red::Switch(TrafficLight *light) {
  light->SetState(std::make_unique<Yellow>());
  light->SetDirection(Direction::TO_GREEN);
}

std::string Red::GetStringState() {
  return "Red";
}
