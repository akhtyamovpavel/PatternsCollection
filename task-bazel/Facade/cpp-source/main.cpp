//
// Created by Pavel Akhtyamov on 2019-03-20.
//

#include <iostream>
#include <Facade/cpp-source/facades/Facade.h>

int main() {
  Facade facade;
  std::cout << facade.CreateNormalGame() << " is normal game" << std::endl;
  std::cout << facade.CreateHardGame() << " is hard game" << std::endl;
  std::cout << facade.CreateVegiburger() << " is burger" << std::endl;
}