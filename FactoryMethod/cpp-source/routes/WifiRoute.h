//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#pragma once

#include "Route.h"

class WifiRoute : public Route {
 public:
  std::string Connect() const override;

};



