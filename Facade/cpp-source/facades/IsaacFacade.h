//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#pragma once

#include <string>
#include <AbstractFactory/cpp-source/serializers/GameSerializer.h>

class IsaacFacade {
 public:
  std::string CreateGame(std::string difficulty);

 private:
  GameSerializer serializer_;
};



