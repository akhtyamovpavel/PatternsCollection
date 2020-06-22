//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#include <mutex>
#include "PlaneDispatcher.h"
bool PlaneDispatcher::Notify(std::shared_ptr<Vehicle> vehicle, std::string message) {
  if (message == "Want to land") {
    std::lock_guard<std::mutex> guard(spared_lane_);
    if (!spare_) {
      return false;
    } else {
      spare_ = false;
      return true;
    }
  } else {
    std::lock_guard<std::mutex> guard(spared_lane_);
    spare_ = true;
    return true;
  }
}

void PlaneDispatcher::AddPlane(std::shared_ptr<Plane> vehicle) {
  vehicle->Connect(shared_from_this());
  vehicles_.push_back(vehicle);
}
