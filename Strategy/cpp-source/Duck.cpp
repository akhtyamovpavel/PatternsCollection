#include <utility>

//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#include "Duck.h"
#include "QuackBehaviour.h"

void Duck::SetFlyBehaviour(std::shared_ptr<FlyBehaviour> behaviour) {
  fly_behaviour_ = std::move(behaviour);
}

void Duck::Fly() {
  fly_behaviour_->Execute();
}

void Duck::Quack() {
  quack_behaviour_->Execute();
}

void Duck::SetQuackBehaviour(std::shared_ptr<QuackBehaviour> quack_behaviour) {
  quack_behaviour_ = std::move(quack_behaviour);
}

void Duck::Swim() {
  swim_behaviour_->Execute();
}

void Duck::SetSwimBehaviour(std::shared_ptr<SwimBehaviour> swim_behaviour) {
  swim_behaviour_ = std::move(swim_behaviour);
}

