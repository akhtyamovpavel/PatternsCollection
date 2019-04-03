//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include <memory>
#include "base/Burger.h"

class BurgerBuilder {
 public:
  virtual void Reset() = 0;
  virtual void AddLowBread() = 0;
  virtual void AddMeat() = 0;
  virtual void AddHighBread() = 0;
  virtual void AddVegetable() = 0;

  virtual std::shared_ptr<Burger> GetBurger() const = 0;
};



