//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#pragma once

#include "BurgerBuilder.h"
#include "base/Burger.h"

class VegiburgerBuilder : public BurgerBuilder {
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


