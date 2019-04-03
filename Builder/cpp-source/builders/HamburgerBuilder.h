//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include "BurgerBuilder.h"
#include "base/Burger.h"

class HamburgerBuilder : public BurgerBuilder {
 public:
  void Reset() override;
  void AddLowBread() override;
  void AddMeat() override;
  void AddHighBread() override;
  void AddVegetable() override;
  std::shared_ptr<Burger> GetBurger() const override;
 private:
  std::vector<std::string> components_;
};

