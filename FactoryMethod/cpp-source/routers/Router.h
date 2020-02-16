//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#pragma once

#include <string>
#include <memory>
#include <routes/Route.h>

class Router {
 public:
  virtual std::shared_ptr<Route> CreateRoute() const = 0;

  std::string ConnectToNet();
};



