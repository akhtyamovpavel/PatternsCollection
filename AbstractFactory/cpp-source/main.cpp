//
// Created by Pavel Akhtyamov on 2019-02-25.
//


#include <iostream>
#include "factories/RoomFactory.h"
#include "factories/BasementFactory.h"
#include "factories/CavesFactory.h"

int main() {
  std::shared_ptr<RoomFactory> basement_factory = std::make_shared<BasementFactory>();

  std::shared_ptr<NormalRoom> normal_room = basement_factory->CreateNormalRoom();
  std::cout << normal_room->GenerateLoot() << " " << normal_room->GenerateBoss() << std::endl;

  std::shared_ptr<HardRoom> hard_room = basement_factory->CreateHardRoom();
  std::cout << hard_room->GenerateLoot() << " " << hard_room->GenerateBoss() << std::endl;

  std::shared_ptr<HardRoom> new_hard_room = basement_factory->CreateHardRoom();
  std::cout << new_hard_room->GenerateLoot() << " " << new_hard_room->GenerateBoss() << std::endl;

  std::cout << "Secret: " << new_hard_room->GenerateSecret(*hard_room) << std::endl;

  std::shared_ptr<RoomFactory> caves_factory = std::make_shared<CavesFactory>();

  std::shared_ptr<NormalRoom> caves_normal_room = caves_factory->CreateNormalRoom();
  std::cout << caves_normal_room->GenerateLoot() << " " << caves_normal_room->GenerateBoss() << std::endl;

  std::shared_ptr<HardRoom> caves_hard_room = caves_factory->CreateHardRoom();
  std::cout << "Secret: " << caves_hard_room->GenerateSecret(*normal_room) << std::endl;

}

