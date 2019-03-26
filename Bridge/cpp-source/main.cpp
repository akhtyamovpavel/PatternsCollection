//
// Created by Pavel Akhtyamov on 2019-03-26.
//


#include <memory>
#include <Axle.h>
#include <CarAxle.h>
#include <Gamepad.h>

int main() {
  std::unique_ptr<Axle> car_axle = std::make_unique<CarAxle>();

  Gamepad gamepad(std::move(car_axle));
  gamepad.PressUpButton();

  for (size_t index = 0; index < 10; ++index) {
    gamepad.PressGasPedal();
    gamepad.PressDownButton();
    gamepad.PressGasPedal();
  }

  gamepad.PushWheel();

  gamepad.PrintInfo();
}

