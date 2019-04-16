//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#include "dispatcher/Dispatcher.h"
#include "dispatcher/PlaneDispatcher.h"

int main() {
  auto plane_dispatcher = std::make_shared<PlaneDispatcher>();

  auto first = std::make_shared<Plane>();
  auto second = std::make_shared<Plane>();

  plane_dispatcher->AddPlane(first);
  plane_dispatcher->AddPlane(second);

  std::thread first_thread(&Plane::Land, first);
  std::thread second_thread(&Plane::Land, second);

  first_thread.join();
  second_thread.join();

}