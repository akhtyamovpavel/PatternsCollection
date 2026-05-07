//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "HamburgerBuilder.h"

void HamburgerBuilder::Reset() {
  components_.clear();
}

void HamburgerBuilder::AddLowBread() {
  components_.emplace_back("WhiteLoaf");
}

void HamburgerBuilder::AddMeat() {
  components_.emplace_back("Farsh");
}

void HamburgerBuilder::AddHighBread() {
  components_.emplace_back("GrayLoaf");
}

void HamburgerBuilder::AddVegetable() {
  components_.emplace_back("Tomato");
}

std::shared_ptr<Burger> HamburgerBuilder::GetBurger() const {
  return std::make_shared<Burger>(components_);
}
