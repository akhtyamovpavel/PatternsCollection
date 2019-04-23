//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include "ElementRoom.h"
class BathRoom : public ElementRoom {
 public:
  void Accept(Visitor *visitor) override;
  std::string GetName() override;

};



