//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "Yellow.h"
#include "../TrafficLight.h"
#include "Red.h"
#include "Green.h"


void Yellow::Switch(TrafficLight *light) {
  if (light->GetDirection() == Direction::TO_GREEN) {
    light->SetState(std::make_unique<Green>());
  } else {
    light->SetState(std::make_unique<Red>());
  }
}

std::string Yellow::GetStringState() {
  return "Yellow";
}
