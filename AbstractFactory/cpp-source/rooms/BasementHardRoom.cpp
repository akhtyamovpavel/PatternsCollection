//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "BasementHardRoom.h"
bool BasementHardRoom::GenerateSecret(const Room &previous_room) const {
  if (previous_room.chance() == 0) {
    return rand() < 10000;
  } else {
    return rand() < 5000;
  }
}

std::string BasementHardRoom::GenerateBoss() const {
  return "200 hp";
}


std::string BasementHardRoom::GenerateLoot() const {
  return "Loot";
}

size_t BasementHardRoom::chance() const {
  return 0;
}
