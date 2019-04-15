//
// Created by Pavel Akhtyamov on 2019-04-09.
//


#include "BaseHandler.h"

void BaseHandler::SetErrorFunction(std::function<void(const std::exception &, const Log &)> function) {
  using namespace std::placeholders;
  reject_ = std::move(function);
  std::bind(reject_, this, _2, _1);
}

void BaseHandler::Handle(const Log &request) {
  try {
    if (next_handler_) {
      next_handler_->Handle(request);
    }
  } catch (const std::exception& e) {
    reject_(e, request);
  }
}

std::shared_ptr<LoggingHandler> BaseHandler::SetNext(std::shared_ptr<LoggingHandler> handler) {
  next_handler_ = std::move(handler);
  return next_handler_;
}

bool BaseHandler::CheckLevel_(const Log &log) const {
  return log_levels_.find(log.level) != log_levels_.end();
}

std::shared_ptr<LoggingHandler> BaseHandler::ToParent() {
  return std::dynamic_pointer_cast<LoggingHandler>(shared_from_this());
}

