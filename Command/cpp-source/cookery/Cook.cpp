//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#include "Cook.h"
#include <thread>
#include <chrono>
#include <iostream>

void Cook::Prepare(std::string dish) {
  for (const std::string& action : recipes_[dish]) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << action << std::endl;
  }
}
