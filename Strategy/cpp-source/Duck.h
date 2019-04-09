//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include <memory>
#include "SimpleFlyBehaviour.h"
class Duck {

 public:
  void SetFlyBehaviour(std::shared_ptr<FlyBehaviour> behaviour);
  void Fly();
 private:
  std::shared_ptr<FlyBehaviour> fly_behaviour_;
};



