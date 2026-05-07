//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "CavesHardRoom.h"
bool CavesHardRoom::GenerateSecret(const Room &previous_room) const {
  if (previous_room.chance() == 3) {
    return rand() < 30000;
  } else if (chance() == 1) {
    return rand() < 15000;
  } else {
    return rand() < 5000;
  }
}

std::string CavesHardRoom::GenerateBoss() const {
  return "400 hp";
}

std::string CavesHardRoom::GenerateLoot() const {
  return "Loot x4";
}

size_t CavesHardRoom::chance() const {
  return 3;
}
