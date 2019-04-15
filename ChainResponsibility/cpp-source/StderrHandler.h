//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include "BaseHandler.h"
class StderrHandler : public BaseHandler {
 public:
  explicit StderrHandler(std::unordered_set<LogLevel> log_levels);
  void Handle(const Log &request);

};



