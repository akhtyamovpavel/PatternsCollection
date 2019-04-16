//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#pragma once

#include <memory>

class Dispatcher;

class Vehicle : public std::enable_shared_from_this<Vehicle> {
 public:
  void Connect(std::shared_ptr<Dispatcher> mediator);
 protected:
  std::shared_ptr<Dispatcher> mediator_;
};



