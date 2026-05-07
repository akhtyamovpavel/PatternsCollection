//
// Created by Pavel Akhtyamov on 2019-03-20.
//

#pragma once

#include "IsaacFacade.h"
#include "BurgerFacade.h"

class Facade {
 public:
  std::string CreateNormalGame();
  std::string CreateHardGame();
  std::string CreateVegiburger();

 private:
  IsaacFacade isaac_facade;
  BurgerFacade burger_facade;
};



