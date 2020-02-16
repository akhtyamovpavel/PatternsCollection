//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#include "WifiRouter.h"

#include <routes/WifiRoute.h>

std::shared_ptr<Route> WifiRouter::CreateRoute() const {
  return std::make_shared<WifiRoute>();
}
