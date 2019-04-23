//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include <string>

class TrafficLight;

class Red;
class Green;
class Yellow;


class State {
 public:
  virtual void Switch(TrafficLight *light) = 0;
  virtual std::string GetStringState() = 0;
};




