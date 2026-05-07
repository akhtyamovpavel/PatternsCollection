//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#pragma once

#include <memory>
#include "builders/BurgerBuilder.h"
class Chef {
 public:
  void SetBuilder(std::shared_ptr<BurgerBuilder> builder);
  std::shared_ptr<Burger> Cook();
 private:
  std::shared_ptr<BurgerBuilder> builder_;
};



