//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "BathRoom.h"

void BathRoom::Accept(Visitor *visitor) {
  visitor->visit(this);
}
std::string BathRoom::GetName() {
  return "BathRoom";
}
