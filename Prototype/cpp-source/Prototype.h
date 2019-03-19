//
// Created by Pavel Akhtyamov on 05/03/2018.
//

#pragma once

#include <memory>
class Prototype {
 public:
  virtual Prototype* clone() const = 0;

  virtual ~Prototype() = default;
};
