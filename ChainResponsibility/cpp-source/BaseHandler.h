//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include "LoggingHandler.h"
#include "LogLevel.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <functional>


class BaseHandler : public LoggingHandler {
 private:
  std::function<void(const std::exception&, const Log&)> reject_;
  std::shared_ptr<LoggingHandler> next_handler_;
  std::unordered_set<LogLevel> log_levels_;

 protected:
  bool CheckLevel_(const Log& log) const;
 public:
  explicit BaseHandler(std::unordered_set<LogLevel> log_levels): log_levels_(log_levels) {}
  virtual void SetErrorFunction(std::function<void(const std::exception&, const Log&)> function);


  virtual void Handle(const Log& request);

  std::shared_ptr<LoggingHandler> SetNext(std::shared_ptr<LoggingHandler> handler);
  std::shared_ptr<LoggingHandler> ToParent();

  virtual ~BaseHandler() = default;
};