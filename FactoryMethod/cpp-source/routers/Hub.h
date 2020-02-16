//
// Created by Pavel Akhtyamov on 2020-02-16.
//

#pragma once
#include <routers/Router.h>

class Hub: public Router {
 public:
  virtual std::shared_ptr<Route> CreateRoute() const override;

};



