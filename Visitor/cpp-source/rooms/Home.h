//
// Created by akhtyamovpavel on 4/29/20.
//


#pragma once

#include "ElementRoom.h"
#include "BathRoom.h"
#include "LivingRoom.h"
#include "Kitchen.h"

class Home : public ElementRoom {
 public:
  void Accept(Visitor *visitor) override;
  std::string GetName() override;
  BathRoom bath_room_;
  LivingRoom living_room_;
  Kitchen kitchen_;
};


