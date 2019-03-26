//
// Created by Pavel Akhtyamov on 2019-03-26.
//


#include <memory>
#include <Axle.h>
#include <CarAxle.h>
#include <PlaneAxle.h>
#include <Gamepad.h>
#include <PlaneWheel.h>

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

  std::unique_ptr<Axle> plane_car_axle = std::make_unique<CarAxle>();

  PlaneWheel plane_wheel(std::move(plane_car_axle));

  for (size_t index = 0; index < 10; ++index) {
    plane_wheel.PullWheel();
  }

  plane_wheel.PrintInfo();

  std::unique_ptr<Axle> plane_axle = std::make_unique<PlaneAxle>();
  PlaneWheel real_plane_wheel(std::move(plane_axle));
  for (size_t index = 0; index < 10; ++index) {
    real_plane_wheel.PullWheel();
  }

  real_plane_wheel.PrintInfo();
}

