//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#pragma once

#include <string>
#include <memory>

#include "../vehicles/Vehicle.h"

class Dispatcher : public std::enable_shared_from_this<Dispatcher> {
 public:
  virtual bool Notify(
      std::shared_ptr<Vehicle> vehicle,
      std::string message
  ) = 0;
};



