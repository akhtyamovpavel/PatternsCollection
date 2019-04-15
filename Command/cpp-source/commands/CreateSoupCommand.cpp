//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#include "CreateSoupCommand.h"

void CreateSoupCommand::Execute() {
  cook_->Prepare(dish_);
}

std::string CreateSoupCommand::ToString() {
  return std::string();
}

uint16_t CreateSoupCommand::GetPrice() {
  return 10;
}

CreateSoupCommand::CreateSoupCommand(
    std::shared_ptr<Cook> cook,
    std::string dish
    ) : cook_(cook), dish_(dish) {

}
