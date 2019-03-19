//
// Created by Pavel Akhtyamov on 26/03/2018.
//

#include "TextJsonAdapter.h"

std::unordered_map<std::string, std::string> TextJsonAdapter::ConvertToJson() {
  std::unordered_map<std::string, std::string> result;

  for (auto key_value_pair : GetPairs()) {
    result[key_value_pair.key] = key_value_pair.value;
  }
  return result;
}


void TextJsonAdapter::Write(const std::string &filename) {
  std::unordered_map<std::string, std::string> pairs = ConvertToJson();
  storage_.SetData(pairs);
  storage_.WriteJson(filename);
}
