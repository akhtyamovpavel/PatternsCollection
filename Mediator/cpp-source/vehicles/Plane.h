//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#pragma once

#include "Vehicle.h"
#include "PlaneCommands.h"

class Plane : public Vehicle {
 public:
  void HasLanded();
  void GetStatus();
  void Land();
 private:
  PlaneCommand status_ = CONNECTED;
};



