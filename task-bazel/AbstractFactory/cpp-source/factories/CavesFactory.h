//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include "RoomFactory.h"


class CavesFactory : public RoomFactory {
 public:
  std::shared_ptr<NormalRoom> CreateNormalRoom() override;
  std::shared_ptr<HardRoom> CreateHardRoom() override;

};



