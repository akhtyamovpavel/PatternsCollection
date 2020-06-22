//
// Created by Pavel Akhtyamov on 2019-04-08.
//

#include <functional>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "LogLevel.h"
#include "LoggingHandler.h"
#include "BaseHandler.h"
#include "DivisionZeroHandler.h"
#include "FileHandler.h"
#include "StderrHandler.h"

int main() {
  std::shared_ptr<BaseHandler> handler = CreateHandler<BaseHandler, BaseHandler>(
      LogLevel::All()
  );
  handler->SetErrorFunction(
    [](
        const std::exception& exception,
        const Log& request
        ) {
      Log output_log{
        .message = exception.what(),
        .level = LogLevel::ERROR
      };

      std::cerr << output_log << std::endl;
    }
  );
  handler->SetNext(CreateHandler<DivisionZeroHandler>({
    LogLevel::INFO,
    LogLevel::ERROR
  }))->SetNext(CreateHandler<FileHandler, FileHandler>({
    LogLevel::DEBUG,
    LogLevel::INFO
  })->SetWriteFile("output.log")->ToParent()
  )->SetNext(CreateHandler<StderrHandler>(
      LogLevel::All()
  ));

  handler->Handle({
    .message = "I want to log this message",
    .level = LogLevel::DEBUG
  });
  handler->Handle({
                      .message = "I want to log this message",
                      .level = LogLevel::INFO
                  });
}