//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#include "Barman.h"
#include <chrono>
#include <thread>

#include <iostream>


void Barman::Prepare(std::string cocktail) {
  for (const std::string& action : recipes_[cocktail]) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << action << std::endl;
  }

  std::cout << "Shake" << std::endl;
  std::cout << "Show" << std::endl;
}
