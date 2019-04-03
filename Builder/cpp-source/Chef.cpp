//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "Chef.h"

void Chef::SetBuilder(std::shared_ptr<BurgerBuilder> builder) {
  builder_ = std::move(builder);
}

std::shared_ptr<Burger> Chef::Cook() {
  builder_->Reset();
  builder_->AddLowBread();
  builder_->AddVegetable();
  builder_->AddMeat();
  builder_->AddVegetable();
  builder_->AddHighBread();
  return std::move(builder_->GetBurger());
}
