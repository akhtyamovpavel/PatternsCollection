//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#include "CreateCocktailCommand.h"
void CreateCocktailCommand::Execute() {
  barman_->Prepare(dish_);
}

uint16_t CreateCocktailCommand::GetPrice() {
  return 100;
}

std::string CreateCocktailCommand::ToString() {
  return std::string();
}
CreateCocktailCommand::CreateCocktailCommand(std::shared_ptr<Barman> barman, std::string dish) :
  barman_(barman),
  dish_(dish) {

}
