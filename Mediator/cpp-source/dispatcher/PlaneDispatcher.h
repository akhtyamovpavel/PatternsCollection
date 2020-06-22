//
// Created by Pavel Akhtyamov on 2019-04-16.
//

#pragma once
#include <memory>
#include <vector>
#include <thread>

#include <mutex>

#include "Dispatcher.h"
#include "../vehicles/Plane.h"


class PlaneDispatcher : public Dispatcher {
 public:
  bool Notify(
      std::shared_ptr<Vehicle> vehicle,
      std::string message
  ) override;
  void AddPlane(std::shared_ptr<Plane> vehicle);

 private:
  std::vector<std::shared_ptr<Vehicle>> vehicles_;
  std::mutex spared_lane_;
  bool spare_ = true;
};



