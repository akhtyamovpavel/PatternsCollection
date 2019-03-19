//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#include <RoomSerializer.h>
#include <NormalRoom.h>
#include <RoomFactory.h>
#include <BasementFactory.h>

#include <memory>
#include <iostream>
#include <cassert>


int main() {
  std::shared_ptr<RoomFactory> basement_factory = std::make_shared<BasementFactory>();

  std::shared_ptr<NormalRoom> normal_room = basement_factory->CreateNormalRoom();
  std::shared_ptr<HardRoom> hard_room = basement_factory->CreateHardRoom();


  RoomSerializer serializer;
  assert(serializer.IsNormalRoom(normal_room));
  std::cout << serializer.SerializeNormalRoom(normal_room) << std::endl;
  std::cout << serializer.SerializeHardRoom(hard_room, normal_room) << std::endl;

}