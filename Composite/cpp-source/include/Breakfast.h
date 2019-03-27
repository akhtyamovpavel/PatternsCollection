//
// Created by Pavel Akhtyamov on 2019-03-27.
//

#pragma once

#include <Dish.h>

class Breakfast : public Dish {
 public:
  size_t GetCalories() override;
  std::shared_ptr<Dish> Add(std::shared_ptr<DishComponent> dish_component) override;

};



