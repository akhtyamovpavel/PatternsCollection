//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#pragma once

#include "Route.h"

class EthernetRoute : public Route {
 public:
  std::string Connect() const override;

};



