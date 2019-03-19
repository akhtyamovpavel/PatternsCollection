//
// Created by Pavel Akhtyamov on 05/03/2018.
//

#pragma once

#include "FerrariPrototype.h"

class PirelliFerrari : public FerrariPrototype {
 private:
  std::string shassi_name;
 public:
  PirelliFerrari(const std::string& shassi_name, const std::string& engine_name);
  PirelliFerrari(const PirelliFerrari& prototype);
  Prototype* clone() const;

  std::string GetShassiName() const {
    return shassi_name;
  };
};
