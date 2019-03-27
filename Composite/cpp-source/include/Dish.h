//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#pragma once

#include <DishComponent.h>
#include <cstddef>
#include <memory>
#include <vector>

class Dish : public DishComponent {
 public:
  size_t GetCalories() override;
  virtual std::shared_ptr<Dish> Add(std::shared_ptr<DishComponent> dish_component);
 private:
  std::vector<std::shared_ptr<DishComponent>> components_;
};



