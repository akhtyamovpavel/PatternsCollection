//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#include <PlaneWheel.h>

void PlaneWheel::PushWheel() {
  axle_->Brake(0.1);
  axle_->MoveDown(0.1);
}

void PlaneWheel::PullWheel() {
  axle_->Accelerate(0.1);
  axle_->MoveUp(0.1);
}

void PlaneWheel::PressGasPedal() {
  axle_->Accelerate(0.1);
}

void PlaneWheel::PressBreakPedal() {
  axle_->Brake(0.1);
  axle_->MoveDown(0.1);
}

void PlaneWheel::PressLeftButton() {
  axle_->Beep();
}

void PlaneWheel::PressRightButton() {
  axle_->PrintInfo();
}

void PlaneWheel::MoveRightWheel(float angle) {
  axle_->MoveRight(angle);
}

void PlaneWheel::MoveLeftWheel(float angle) {
  axle_->MoveLeft(angle);
}

void PlaneWheel::PressUpButton() {}

void PlaneWheel::PressDownButton() {}

void PlaneWheel::PrintInfo() {
  axle_->PrintInfo();
}

PlaneWheel::PlaneWheel(std::unique_ptr<Axle> axle) : SteeringWheel(std::move(axle)) {

}
