//
// Created by Pavel Akhtyamov on 05/03/2018.
//

#include "PirelliFerrari.h"


PirelliFerrari::PirelliFerrari(const std::string &shassi_name,
                               const std::string &engine_name) :
    FerrariPrototype(engine_name) {
  this->shassi_name = shassi_name;
}

PirelliFerrari::PirelliFerrari(const PirelliFerrari &prototype) :
    FerrariPrototype(prototype) {
  this->shassi_name = prototype.shassi_name;
}

Prototype* PirelliFerrari::clone() const {
  return new PirelliFerrari(*this);
}


