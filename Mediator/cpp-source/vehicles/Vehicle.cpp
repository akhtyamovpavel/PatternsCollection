//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#include "Vehicle.h"

void Vehicle::Connect(std::shared_ptr<Dispatcher> mediator) {
  mediator_ = mediator;
}
