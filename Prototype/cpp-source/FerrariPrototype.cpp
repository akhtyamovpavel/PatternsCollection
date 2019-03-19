//
// Created by Pavel Akhtyamov on 05/03/2018.
//

#include "FerrariPrototype.h"
FerrariPrototype::FerrariPrototype(const FerrariPrototype &prototype) {
  engine_name = prototype.engine_name;
}

Prototype* FerrariPrototype::clone() const {
  return new FerrariPrototype(*this);
}

FerrariPrototype::FerrariPrototype(const std::string &engine_name) {
  this->engine_name = engine_name;
}

