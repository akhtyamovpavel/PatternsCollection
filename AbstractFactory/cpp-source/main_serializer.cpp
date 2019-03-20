//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#include <RoomSerializer.h>
#include <NormalRoom.h>
#include <RoomFactory.h>
#include <BasementFactory.h>
#include <GameSerializer.h>

#include <memory>
#include <iostream>
#include <cassert>
#include <vector>

int main() {
  std::shared_ptr<RoomFactory> basement_factory = std::make_shared<BasementFactory>();

  std::shared_ptr<NormalRoom> normal_room = basement_factory->CreateNormalRoom();
  std::shared_ptr<HardRoom> hard_room = basement_factory->CreateHardRoom();


  RoomSerializer serializer;
  assert(serializer.IsNormalRoom(normal_room));

  GameSerializer game_serializer;
  std::vector<std::shared_ptr<Room>> rooms;

  rooms.push_back(std::dynamic_pointer_cast<Room>(normal_room));
  rooms.push_back(std::dynamic_pointer_cast<Room>(hard_room));

  std::cout << game_serializer.SerializeGame(rooms) << std::endl;

//  std::cout << serializer.SerializeNormalRoom(normal_room) << std::endl;
//  std::cout << serializer.SerializeHardRoom(hard_room, normal_room) << std::endl;

}