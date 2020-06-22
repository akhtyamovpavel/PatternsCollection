//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#include "Waiter.h"
#include "commands/CreateSoupCommand.h"
#include "cookery/CookPool.h"
#include "Dish.h"
#include "commands/CreateCocktailCommand.h"

#include <thread>
#include <iostream>
#include <string>


void ProcessCommand(Waiter& waiter, Dish dish) {
  if (dish.menu == "soup") {
    std::shared_ptr<Command> command_class = std::make_shared<CreateSoupCommand>(
        CookPool::GetCook(), dish.dish
    );
    waiter.SetCommand(command_class);
  } else if (dish.menu == "cocktail") {
    std::shared_ptr<Command> command_class = std::make_shared<CreateCocktailCommand>(
      CookPool::GetBarman(), dish.dish
    );
    waiter.SetCommand(command_class);
  }
//  waiter.ExecuteCommand();
  std::thread thread(&Waiter::ExecuteCommand, waiter);
  thread.detach();
}


int main() {
  std::string menu;
  Waiter waiter;
  while (std::getline(std::cin, menu)) {
    std::string dish;
    std::getline(std::cin, dish);
    ProcessCommand(waiter, {
      .menu = menu,
      .dish = dish
    });
    std::cerr << "Ready" << std::endl;
  }
}
