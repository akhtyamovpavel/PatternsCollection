//
// Created by Pavel Akhtyamov on 2019-04-09.
//


#include "DivisionZeroHandler.h"
DivisionZeroHandler::DivisionZeroHandler(std::unordered_set<LogLevel> log_levels) : BaseHandler(log_levels) {

}

void DivisionZeroHandler::Handle(const Log &request) {
  if (CheckLevel_(request)) {
    throw std::runtime_error("Hobana");
  } else {
    BaseHandler::Handle(request);
  }
}
