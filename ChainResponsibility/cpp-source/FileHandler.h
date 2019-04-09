//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#pragma once

#include <fstream>
#include <string>
#include "BaseHandler.h"

class FileHandler: public BaseHandler {
 public:
  void Handle(const Log &request);
  std::shared_ptr<FileHandler> SetWriteFile(std::string path);
  ~FileHandler();
 private:
 public:
  explicit FileHandler(std::unordered_set<LogLevel> log_levels);
 private:
  std::ofstream output_;
  std::string path_;

};



