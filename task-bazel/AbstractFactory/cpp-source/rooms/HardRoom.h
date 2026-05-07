//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include "Room.h"

class HardRoom : public Room {
 public:
  virtual bool GenerateSecret(const Room& previous_room) const = 0;
  virtual ~HardRoom() = default;
};


