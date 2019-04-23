#include <utility>

//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "PasswordMemento.h"

namespace memento {

PasswordMemento::PasswordMemento(State state) : state_(std::move(state)) {}

std::string PasswordMemento::GetName() {
  return state_.save_name;
}

State PasswordMemento::GetState() {
  return state_;
}

}