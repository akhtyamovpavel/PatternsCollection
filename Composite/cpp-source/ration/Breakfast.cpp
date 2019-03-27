//
// Created by Pavel Akhtyamov on 2019-03-27.
//

#include <Breakfast.h>

size_t Breakfast::GetCalories() {
  return Dish::GetCalories() + 10;
}

std::shared_ptr<Dish> Breakfast::Add(std::shared_ptr<DishComponent> dish_component) {
  return Dish::Add(dish_component);
}
