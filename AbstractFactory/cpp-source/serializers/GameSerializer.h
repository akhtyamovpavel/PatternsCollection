//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#pragma once

#include <string>
#include <memory>
#include <Room.h>

class GameSerializer {
 public:
  std::string SerializeGame(const std::vector<std::shared_ptr<Room>> &rooms);
};



