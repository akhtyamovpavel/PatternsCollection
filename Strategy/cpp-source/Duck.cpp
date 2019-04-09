#include <utility>

//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#include "Duck.h"
void Duck::SetFlyBehaviour(std::shared_ptr<FlyBehaviour> behaviour) {
  fly_behaviour_ = std::move(behaviour);
}

void Duck::Fly() {
  fly_behaviour_->Execute();
}
