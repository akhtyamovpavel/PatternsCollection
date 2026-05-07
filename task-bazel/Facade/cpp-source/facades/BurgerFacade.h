//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#pragma once

#include <string>
#include <Builder/cpp-source/Chef.h>

class BurgerFacade {
 public:
  std::string createHamburger();
  std::string createVegiburger();
  std::string createBurger(const std::string& type);
 private:
  Chef chef_;
};

