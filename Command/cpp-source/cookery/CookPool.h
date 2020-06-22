//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#pragma once

#include <memory>
#include "Cook.h"
#include "Barman.h"

class CookPool {
 public:
  static std::shared_ptr<Cook> GetCook();
  static std::shared_ptr<Barman> GetBarman();
 private:
  static std::shared_ptr<Cook> cook_;
  static std::shared_ptr<Barman> barman_;
};



