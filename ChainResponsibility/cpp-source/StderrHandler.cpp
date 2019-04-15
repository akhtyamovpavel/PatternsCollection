//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#include "StderrHandler.h"
StderrHandler::StderrHandler(std::unordered_set<LogLevel> log_levels) : BaseHandler(log_levels) {

}

void StderrHandler::Handle(const Log &request) {
  if (CheckLevel_(request)) {
    std::cerr << request;
  }
  BaseHandler::Handle(request);
}
