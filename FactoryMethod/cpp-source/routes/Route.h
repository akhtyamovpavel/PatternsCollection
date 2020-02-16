//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#pragma once

#include <string>


class Route {
 public:
  virtual std::string Connect() const = 0;
};



