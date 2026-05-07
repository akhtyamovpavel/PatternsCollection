//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "CavesNormalRoom.h"

std::string CavesNormalRoom::GenerateBoss() const {
  return "300 hp";
}

std::string CavesNormalRoom::GenerateLoot() const {
  return "Loot x3";
}

size_t CavesNormalRoom::chance() const {
  return 2;
}
