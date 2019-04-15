//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <functional>
#include <utility>


class LogLevel {
 public:
  enum Value {
    INFO,
    ERROR,
    WARNING,
    DEBUG
  };

  LogLevel() = default;

  constexpr LogLevel(Value log_level_);
  bool operator ==(const LogLevel& a) const;

  size_t GetValue() const;

  static std::initializer_list<LogLevel> All();
 private:
  Value value_;
};

std::ostream& operator << (std::ostream& ostream, const LogLevel& level);


namespace std {
template <>
struct hash<LogLevel> {
  size_t operator()(const LogLevel& log_level) const {
    return log_level.GetValue();
  }
};
}