//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "Green.h"
#include "Yellow.h"
#include "../TrafficLight.h"

void Green::Switch(TrafficLight *light) {
  light->SetState(std::make_unique<Yellow>());
  light->SetDirection(Direction::TO_RED);
}

std::string Green::GetStringState() {
  return "Green";
}
