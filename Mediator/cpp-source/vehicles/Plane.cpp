//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#include "Plane.h"
#include "../dispatcher/Dispatcher.h"

#include <iostream>
#include <thread>

void Plane::HasLanded() {
  mediator_->Notify(shared_from_this(), "Landed");
}

void Plane::GetStatus() {
  switch (status_) {
    case LANDED: std::cout << "Landed" << std::endl;
      break;
    case ATTACHED: std::cout << "Attached" << std::endl;
      break;
    case CONNECTED: std::cout << "Connected" << std::endl;
      break;
  }
}

void Plane::Land() {
  GetStatus();

  bool land_started = false;
  while (!land_started) {
    land_started = mediator_->Notify(
        shared_from_this(), "Want to land"
      );
    std::this_thread::sleep_for(
        std::chrono::milliseconds(580)
    );
  }

  status_ = ATTACHED;
  GetStatus();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  status_ = LANDED;
  mediator_->Notify(shared_from_this(), "Landed");
  GetStatus();
}
