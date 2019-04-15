//
// Created by Pavel Akhtyamov on 2019-04-09.
//


#include "LogLevel.h"


constexpr LogLevel::LogLevel(LogLevel::Value log_level_): value_(log_level_) {}

bool LogLevel::operator ==(const LogLevel& a) const {
  return value_ == a.value_;
}

std::initializer_list<LogLevel> LogLevel::All() {
  return {
      LogLevel::INFO,
      LogLevel::ERROR,
      LogLevel::DEBUG,
      LogLevel::WARNING
  };
}

size_t LogLevel::GetValue() const {
  return value_;
}


std::ostream& operator << (std::ostream& ostream, const LogLevel& level) {
  std::unordered_map<LogLevel, std::string> strings {
      {LogLevel::INFO, "INFO"},
      {LogLevel::DEBUG, "DEBUG"},
      {LogLevel::WARNING, "WARNING"},
      {LogLevel::ERROR, "ERROR"}
  };

  return ostream << strings[level];
}
