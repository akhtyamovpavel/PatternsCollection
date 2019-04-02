//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#include <Dish.h>

size_t Dish::GetCalories() {
  size_t result = 0;
  for (auto component : components_) {
    result += component->GetCalories();
  }
  return result;
}

std::shared_ptr<Dish> Dish::Add(std::shared_ptr<DishComponent> dish_component) {
  components_.push_back(std::move(dish_component));
  return std::dynamic_pointer_cast<Dish>(shared_from_this());
}