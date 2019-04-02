//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#include <memory>
#include <iostream>
#include <Dish.h>
#include <Milk.h>
#include <Breakfast.h>


template <typename T>
std::shared_ptr<DishComponent> CreateDishComponent() {
  return std::dynamic_pointer_cast<DishComponent>(std::make_shared<T>());
}

template <typename T>
std::shared_ptr<Dish> CreateDish() {
  return std::dynamic_pointer_cast<Dish>(std::make_shared<T>());
}



int main() {
  auto ration = std::make_shared<Dish>()->Add(
      CreateDish<Breakfast>()
          ->Add(CreateDishComponent<Milk>())
          ->Add(CreateDishComponent<Milk>())
    )->Add(
      CreateDishComponent<Milk>()
  );

  std::cout << ration->GetCalories() << std::endl;
}