//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#include "Router.h"

std::string Router::ConnectToNet() {
  auto route = CreateRoute();
  return route->Connect();
}

