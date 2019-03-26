#include <utility>

//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#include <Gamepad.h>


void Gamepad::PushWheel() {
  axle_->Beep();
}

void Gamepad::PullWheel() {
}

void Gamepad::PressGasPedal() {
  axle_->Accelerate(0.1);
}

void Gamepad::PressBreakPedal() {
  axle_->Brake(0.1);
}

void Gamepad::PressLeftButton() {
  axle_->MoveLeft(0.1);
}

void Gamepad::PressRightButton() {
  axle_->MoveRight(0.1);
}

void Gamepad::MoveRightWheel(float angle) {}

void Gamepad::MoveLeftWheel(float angle) {}

void Gamepad::PressUpButton() {
  axle_->MoveDown(0.1);
}

void Gamepad::PressDownButton() {
  axle_->MoveUp(0.1);
}

Gamepad::Gamepad(std::unique_ptr<Axle> ax) : SteeringWheel(std::move(ax)) {

}

void Gamepad::PrintInfo() {
  axle_->PrintInfo();
}
