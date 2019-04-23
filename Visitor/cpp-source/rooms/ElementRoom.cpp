//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "ElementRoom.h"

#include <iostream>
#include <iomanip>

void Surface::Show() {
  std::cout << "Material: " << material << std::endl;
  std::cout << "Color: " << color << std::endl;
}

void ElementRoom::ShowDecorations() {
  std::cout << "Contents of " << GetName() << std::endl;
  std::cout << "--Wall--" << std::endl;
  wall.Show();
  std::cout << "--Floor--" << std::endl;
  floor.Show();
  std::cout << "--Ceiling--" << std::endl;
  ceiling.Show();
}
