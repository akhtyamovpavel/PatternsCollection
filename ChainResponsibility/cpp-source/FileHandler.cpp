//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#include "FileHandler.h"

void FileHandler::Handle(const Log &request) {
  if (CheckLevel_(request)) {
    if (path_.empty()) {
      throw std::invalid_argument("path is empty");
    }
    output_ << request;
  }
  BaseHandler::Handle(request);
}


FileHandler::~FileHandler() {
  output_.close();
}

std::shared_ptr<FileHandler> FileHandler::SetWriteFile(std::string path) {
  path_ = path;
  output_ = std::ofstream(path, std::ios::app | std::ios::out);
  return std::dynamic_pointer_cast<FileHandler>(shared_from_this());
}

FileHandler::FileHandler(std::unordered_set<LogLevel> log_levels) : BaseHandler(log_levels) {

}
