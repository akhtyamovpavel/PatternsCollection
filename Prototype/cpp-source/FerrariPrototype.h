//
// Created by Pavel Akhtyamov on 05/03/2018.
//

#pragma once

#include "Prototype.h"
#include <string>

class FerrariPrototype : public Prototype {
 private:
  std::string engine_name;
 public:
  explicit FerrariPrototype(const std::string& engine_name);
  FerrariPrototype(const FerrariPrototype& prototype);
  virtual Prototype* clone() const;

  std::string GetEngineName() const {
    return engine_name;
  };

  virtual ~FerrariPrototype() = default;
};

