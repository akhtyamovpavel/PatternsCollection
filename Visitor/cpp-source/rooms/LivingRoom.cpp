//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "LivingRoom.h"

#include "../workers/Tiler.h"

void LivingRoom::Accept(Visitor *visitor) {
  visitor->visit(this);
}

std::string LivingRoom::GetName() {
  return "LivingRoom";
}

void LivingRoom::Accept(Tiler *tiler) {

}
