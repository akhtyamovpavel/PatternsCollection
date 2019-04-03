//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include <memory>
#include <iostream>
#include "Chef.h"
#include "builders/BurgerBuilder.h"
#include "builders/HamburgerBuilder.h"


int main() {
  Chef chef;
  std::shared_ptr<BurgerBuilder> hamburger_builder = std::make_shared<HamburgerBuilder>();
  chef.SetBuilder(hamburger_builder);
  std::shared_ptr<Burger> burger = chef.Cook();

  std::cout << burger << std::endl;
}
