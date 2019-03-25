//
// Created by Pavel Akhtyamov on 2019-03-20.
//

#include "Facade.h"

std::string Facade::CreateNormalGame() {
  return isaac_facade.CreateGame("normal");
}

std::string Facade::CreateHardGame() {
  return isaac_facade.CreateGame("hard");
}
std::string Facade::CreateVegiburger() {
  return burger_facade.createVegiburger();
}
