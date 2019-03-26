#include <utility>

//
// Created by Pavel Akhtyamov on 2019-03-26.
//

#include <SteeringWheel.h>

SteeringWheel::SteeringWheel(std::unique_ptr<Axle> axle): axle_(std::move(axle)) {}
