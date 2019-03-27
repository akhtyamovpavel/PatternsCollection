//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#pragma once

#include <cstddef>
#include <memory>

class DishComponent : public std::enable_shared_from_this<DishComponent> {
 public:
  virtual size_t GetCalories() = 0;
};



