//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include "ElementRoom.h"

#include "../workers/Tiler.h"
class LivingRoom : public ElementRoom {
 public:
  void Accept(Visitor *visitor) override;
  void Accept(Tiler* tiler);
  std::string GetName() override;
};



