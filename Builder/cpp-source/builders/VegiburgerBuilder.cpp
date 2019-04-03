//
// Created by Pavel Akhtyamov on 2019-03-19.
//

#include "VegiburgerBuilder.h"

void VegiburgerBuilder::Reset() {
  components_.clear();
}

void VegiburgerBuilder::AddLowBread() {
  components_.emplace_back("GrayLoaf");
}

void VegiburgerBuilder::AddMeat() {
  components_.emplace_back("Farsh");
}

void VegiburgerBuilder::AddHighBread() {
  components_.emplace_back("BlackLoaf");
}

void VegiburgerBuilder::AddVegetable() {
  components_.emplace_back("Salade");
}

std::shared_ptr<Burger> VegiburgerBuilder::GetBurger() const {
  return std::make_shared<Burger>(components_);
}

