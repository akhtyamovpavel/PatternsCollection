//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#include "RoomSerializer.h"

#include <sstream>
#include <iomanip>

std::string RoomSerializer::SerializeNormalRoom(std::shared_ptr<NormalRoom> room) {
  std::stringstream buffer;
  buffer << "{";

  buffer << std::quoted("class") << ":";
  buffer << std::quoted(typeid(*room).name()) << ",";
  buffer << std::quoted("boss") << ":";
  buffer << std::quoted(room->GenerateBoss()) << ",";
  buffer << std::quoted("loot") << ":";
  buffer << std::quoted(room->GenerateLoot()) << "}";
  return buffer.str();
}

std::string RoomSerializer::SerializeHardRoom(
    std::shared_ptr<HardRoom> room,
    std::shared_ptr<Room> previous_room
) {
  std::stringstream buffer;
  buffer << "{";

  buffer << std::quoted("class") << ":";
  buffer << std::quoted(typeid(*room).name()) << ",";
  buffer << std::quoted("boss") << ":";
  buffer << std::quoted(room->GenerateBoss()) << ",";
  buffer << std::quoted("loot") << ":";
  buffer << std::quoted(room->GenerateLoot()) << ",";
  buffer << std::quoted("secret") << ":";
  buffer << std::quoted(std::to_string(room->GenerateSecret(*previous_room))) << "}";
  return buffer.str();
}

bool RoomSerializer::IsNormalRoom(std::shared_ptr<Room> room) {
  return std::dynamic_pointer_cast<NormalRoom>(room) != nullptr;
}
