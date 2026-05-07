//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#include <AbstractFactory/cpp-source/rooms/Room.h>
#include <AbstractFactory/cpp-source/factories/RoomFactory.h>
#include <AbstractFactory/cpp-source/factories/BasementFactory.h>
#include <AbstractFactory/cpp-source/factories/CavesFactory.h>
#include <vector>
#include "IsaacFacade.h"


std::string IsaacFacade::CreateGame(std::string difficulty) {
  std::vector<std::shared_ptr<Room>> rooms;

  std::shared_ptr<RoomFactory> basement_factory = std::make_shared<BasementFactory>();
  std::shared_ptr<RoomFactory> caves_factory = std::make_shared<CavesFactory>();
  if (difficulty == "normal") {
    rooms.push_back(basement_factory->CreateNormalRoom());
    rooms.push_back(basement_factory->CreateNormalRoom());
    rooms.push_back(caves_factory->CreateNormalRoom());
    rooms.push_back(caves_factory->CreateHardRoom());
  } else {
    rooms.push_back(basement_factory->CreateNormalRoom());
    rooms.push_back(basement_factory->CreateHardRoom());
    rooms.push_back(caves_factory->CreateHardRoom());
    rooms.push_back(caves_factory->CreateHardRoom());
  }
  return serializer_.SerializeGame(rooms);
}
