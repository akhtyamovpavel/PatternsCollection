//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#pragma once

#include <string>

class Notifier {
 public:
  virtual void Notify(const std::string& message) = 0;
};



