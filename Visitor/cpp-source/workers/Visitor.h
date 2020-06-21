//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

class Kitchen;
class LivingRoom;
class BathRoom;

class Home;

class Visitor {
 public:
  virtual void visit(Kitchen* kitchen) = 0;
  virtual void visit(LivingRoom* living_room) = 0;
  virtual void visit(BathRoom* bath_room) = 0;
  virtual void visit(Home* home) = 0;
};



