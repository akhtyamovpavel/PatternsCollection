//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#include "Duck.h"
#include "SimpleFlyBehaviour.h"
#include "DuckHuntFlyBehaviour.h"
#include "SimpleQuackBehaviour.h"

int main() {
  Duck duck;
  duck.SetFlyBehaviour(std::make_shared<SimpleFlyBehaviour>());
  duck.Fly();
  duck.SetQuackBehaviour(std::make_shared<SimpleQuackBehaviour>());
  duck.Quack();

  Duck duck_hunt;
  duck_hunt.SetFlyBehaviour(std::make_shared<DuckHuntFlyBehaviour>());
  duck_hunt.Fly();
  duck.SetQuackBehaviour(std::make_shared<SimpleQuackBehaviour>());
  duck_hunt.Quack();

}