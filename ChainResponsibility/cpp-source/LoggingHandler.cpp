//
// Created by Pavel Akhtyamov on 2019-04-09.
//

#include "LoggingHandler.h"

std::ostream &operator<<(std::ostream &ostream, const Log &log) {
  return ostream << "[" << log.level << "]" << " " << log.message << "\n";
}
