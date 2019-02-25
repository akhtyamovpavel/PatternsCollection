//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "BasementNormalRoom.h"

std::string BasementNormalRoom::GenerateBoss() const {
  return "100 hp";
}

std::string BasementNormalRoom::GenerateLoot() const {
  return "Loot";
}

size_t BasementNormalRoom::chance() const {
  return 1;
}
