//
// Created by Pavel Akhtyamov on 2019-04-24.
//

#pragma once

#include "Visitor.h"

class SanTech : public Visitor {
 public:
  void visit(Kitchen *kitchen) override;
  void visit(LivingRoom *living_room) override;
  void visit(BathRoom *bath_room) override;
  void visit(Home *home) override;

};



