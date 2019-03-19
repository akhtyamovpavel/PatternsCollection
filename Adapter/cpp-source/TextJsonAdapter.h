//
// Created by Pavel Akhtyamov on 26/03/2018.
//

#pragma once

#include "TextStorage.h"
#include "JsonStorage.h"


class TextJsonAdapter : public TextStorage {
 private:
  JsonStorage storage_;
  std::unordered_map<std::string, std::string> ConvertToJson();
 public:
  void Write(const std::string& filename);
};
