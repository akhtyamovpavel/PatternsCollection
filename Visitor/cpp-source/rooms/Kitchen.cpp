//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "Kitchen.h"

void Kitchen::Accept(Visitor *visitor) {
  visitor->visit(this);
}

std::string Kitchen::GetName() {
  return "Kitchen";
}
