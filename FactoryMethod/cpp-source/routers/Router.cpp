//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#include "Router.h"

std::string Router::ConnectToNet() {
  std::shared_ptr<Route> route = std::dynamic_pointer_cast<Route>(CreateRoute());
  return route->Connect();
}
