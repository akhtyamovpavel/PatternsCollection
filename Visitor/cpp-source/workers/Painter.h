//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include "Visitor.h"
#include "../rooms/ElementRoom.h"
class Painter : public Visitor {
 public:
  void visit(Kitchen *kitchen) override;
  void visit(LivingRoom *living_room) override;
  void visit(BathRoom *bath_room) override;
  void Paint(Surface* surface, std::string color);
  void visit(Home *home) override;
};



