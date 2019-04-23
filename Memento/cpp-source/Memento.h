//
// Created by Pavel Akhtyamov on 2019-04-22.
//

#pragma once

#include <string>

namespace memento {

using Level = size_t;
using Progress = uint8_t;
using Place = std::string;

struct State {
  Place place;
  Level level;
  Progress progress;
  std::string save_name;
};

static Progress DEFAULT_PROGRESS_LEVEL = 5;

class Memento {
 public:
  virtual std::string GetName() = 0;
  virtual State GetState() = 0;
};

} // namespace Memento



