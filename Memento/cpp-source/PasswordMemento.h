//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include "Memento.h"

namespace memento {

class PasswordMemento : public Memento {
 public:
  explicit PasswordMemento(State state);
  std::string GetName() override;
  State GetState() override;
  ~PasswordMemento() = default;
 private:
  State state_;
};

} // namespace memento



