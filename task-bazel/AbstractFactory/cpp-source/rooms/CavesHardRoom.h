//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include "HardRoom.h"

class CavesHardRoom : public HardRoom {
 public:
  bool GenerateSecret(const Room &previous_room) const override;
  std::string GenerateBoss() const override;
  std::string GenerateLoot() const override;
  size_t chance() const override;

};



