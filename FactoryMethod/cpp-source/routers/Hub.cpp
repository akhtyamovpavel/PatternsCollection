//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#include "Hub.h"

#include <routes/EthernetRoute.h>

std::shared_ptr<Route> Hub::CreateRoute() const {
  return std::make_shared<EthernetRoute>();
}
