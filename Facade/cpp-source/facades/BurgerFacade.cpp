//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#include "BurgerFacade.h"

#include <iostream>
#include <memory>

#include <Builder/cpp-source/builders/BurgerBuilder.h>
#include <Builder/cpp-source/builders/HamburgerBuilder.h>
#include <Builder/cpp-source/builders/VegiburgerBuilder.h>

std::string BurgerFacade::createHamburger() {
  std::shared_ptr<BurgerBuilder> hamburger_builder = std::make_shared<HamburgerBuilder>();
  chef_.SetBuilder(hamburger_builder);
  std::shared_ptr<Burger> burger = chef_.Cook();
  return burger->serialize();
}

std::string BurgerFacade::createVegiburger() {
  std::shared_ptr<BurgerBuilder> hamburger_builder = std::make_shared<HamburgerBuilder>();
  chef_.SetBuilder(hamburger_builder);
  std::shared_ptr<Burger> burger = chef_.Cook();
  return burger->serialize();
}

std::string BurgerFacade::createBurger(const std::string &type) {
  if (type == "hamburger") {
    return createHamburger();
  } else {
    return createVegiburger();
  }
}

