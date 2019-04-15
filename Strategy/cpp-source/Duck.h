//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include <memory>
#include "SimpleFlyBehaviour.h"
#include "QuackBehaviour.h"
#include "SwimBehaviour.h"

class Duck {

 public:
  void SetFlyBehaviour(std::shared_ptr<FlyBehaviour> behaviour);
  void Fly();
  void Quack();
  void SetQuackBehaviour(std::shared_ptr<QuackBehaviour> quack_behaviour);
  void Swim();
  void SetSwimBehaviour(std::shared_ptr<SwimBehaviour> swim_behaviour);
 private:
  std::shared_ptr<FlyBehaviour> fly_behaviour_;
  std::shared_ptr<QuackBehaviour> quack_behaviour_;
  std::shared_ptr<SwimBehaviour> swim_behaviour_;
};



