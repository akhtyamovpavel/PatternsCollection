//
// Created by Pavel Akhtyamov on 2019-04-23.
//


#include "TrafficLight.h"
int main() {
  TrafficLight light;
  for (size_t state_switch = 0;
      state_switch < 10;
      ++state_switch) {
    light.PrintState();
    light.ChangeColor();
  }
}