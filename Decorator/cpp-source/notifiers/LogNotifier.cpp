//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#include <LogNotifier.h>

void LogNotifier::Notify(const std::string &message) {
  stream_ << message << std::endl;
}

LogNotifier::LogNotifier(const std::string &filename) {
  stream_.open(filename, std::ofstream::out | std::ofstream::app);
}

LogNotifier::~LogNotifier() {
  stream_.close();
}
