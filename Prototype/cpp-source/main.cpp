#include <iostream>
#include <vector>
#include "PirelliFerrari.h"

int main() {

  PirelliFerrari machine("Pirelli", "Ferrari");
  FerrariPrototype prototype("BMW");

  std::vector<Prototype*> machines {&machine, &prototype};

  std::vector<Prototype*> clones;

  clones.reserve(machines.size());

  for (Prototype* vehicle : machines) {
    clones.push_back(vehicle->clone());
  }

  for (Prototype* vehicle : clones) {
    auto * actual_prototype = dynamic_cast<FerrariPrototype*>(vehicle);
    if (actual_prototype == nullptr) {
      std::cout << "Could not casted to FerrariPrototype" << std::endl;
    } else {
      std::cout << actual_prototype->GetEngineName() << " is cloned" << std::endl;
    }

    auto * pirelli = dynamic_cast<PirelliFerrari*>(vehicle);
    if (pirelli == nullptr) {
      std::cout << "Could not casted to PirelliFerrari" << std::endl;
    } else {
      std::cout << pirelli->GetShassiName() << " shassi is cloned" << std::endl;
    }
  }

  for (Prototype * vehicle: clones){
    delete vehicle;
  }

  return 0;
}