//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include "BaseHandler.h"
#include "LoggingHandler.h"
#include "LogLevel.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <functional>


class DivisionZeroHandler: public BaseHandler {
 public:
  explicit DivisionZeroHandler(std::unordered_set<LogLevel> log_levels);
  void Handle(const Log& request);
};