#include <utility>

//
// Created by Pavel Akhtyamov on 2019-02-25.
//

#include "Burger.h"

#include <sstream>

Burger::Burger(std::vector<std::string> components): components_(std::move(components)) {}


std::ostream &operator<<(std::ostream &ostream, const Burger& burger) {
  ostream << std::string("Burger contents:\n");
  for (const std::string &component : burger.components_) {
    ostream << component << std::string("\n");
  }
  return ostream;
}

std::string Burger::serialize() const {
  std::stringstream buffer;
  buffer << "[";

  for (const std::string &component : components_) {
    buffer << component;
    if (&component != &components_.back()) {
      buffer << ", ";
    }
  }
  buffer << "]";
  return buffer.str();
}
