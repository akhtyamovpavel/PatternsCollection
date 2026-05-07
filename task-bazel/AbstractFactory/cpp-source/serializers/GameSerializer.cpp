//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#include "GameSerializer.h"
#include "RoomSerializer.h"

#include <sstream>
#include <vector>

std::string GameSerializer::SerializeGame(const std::vector<std::shared_ptr<Room>> &rooms) {
  std::stringstream buffer;
  buffer << "[";

  std::shared_ptr<Room> previous_room = nullptr;
  RoomSerializer serializer;
  for (auto room : rooms) {
    if (serializer.IsNormalRoom(room)) {
      buffer << serializer.SerializeNormalRoom(
          std::dynamic_pointer_cast<NormalRoom>(room)
      ) << ", ";
    } else {
      buffer << serializer.SerializeHardRoom(
          std::dynamic_pointer_cast<HardRoom>(room), previous_room
      ) << ", ";
    }
    previous_room = room;
  }
  buffer << "]";
  return buffer.str();
}
