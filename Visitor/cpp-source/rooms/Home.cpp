//
// Created by akhtyamovpavel on 4/29/20.
//

#include "Home.h"
void Home::Accept(Visitor *visitor) {
  visitor->visit(this);
}

std::string Home::GetName() {
  return "Home";
}
