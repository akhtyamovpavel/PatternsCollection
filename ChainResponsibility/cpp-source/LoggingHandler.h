//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include "LogLevel.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <functional>
#include "LoggingHandler.h"

struct Log {
  std::string message;
  LogLevel level;

  friend std::ostream& operator << (std::ostream& ostream, const Log& log);
};


class LoggingHandler : public std::enable_shared_from_this<LoggingHandler> {
 public:
  virtual std::shared_ptr<LoggingHandler> SetNext(std::shared_ptr<LoggingHandler> handler) = 0;
  virtual void Handle(const Log& request) = 0;
};


template<typename T, typename U = LoggingHandler>
std::shared_ptr<U> CreateHandler(std::initializer_list<LogLevel> levels) {
  return std::dynamic_pointer_cast<U>(
      std::make_shared<T>(std::unordered_set<LogLevel>(levels))
  );
}