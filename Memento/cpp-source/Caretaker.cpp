//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "Caretaker.h"
#include <iostream>

namespace memento {

StateNames Caretaker::GetSaves() {
  StateNames names;
  for (auto item : mementos_) {
    names.insert(item.first);
  }
  return names;
}

Caretaker::Caretaker(Originator *originator) : originator_(originator) {}

Caretaker::~Caretaker() {
  for (const auto& memento: mementos_) {
    delete memento.second;
  }
}

void Caretaker::Save(std::string save_name) {
  mementos_[save_name] = originator_->Save(save_name);
}

void Caretaker::Load(std::string save_name) {
  originator_->Restore(mementos_[save_name]);
}

}