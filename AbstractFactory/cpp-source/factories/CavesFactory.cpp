//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "CavesFactory.h"
#include "../rooms/CavesNormalRoom.h"
#include "../rooms/CavesHardRoom.h"

std::shared_ptr<NormalRoom> CavesFactory::CreateNormalRoom() {
  return std::make_shared<CavesNormalRoom>();
}

std::shared_ptr<HardRoom> CavesFactory::CreateHardRoom() {
  return std::make_shared<CavesHardRoom>();
}
