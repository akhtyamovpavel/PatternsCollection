//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include "NormalRoom.h"

class CavesNormalRoom : public NormalRoom {
 public:
  std::string GenerateBoss() const override;
  std::string GenerateLoot() const override;
  size_t chance() const override;
  ~CavesNormalRoom() override = default;
};



