//
// Created by Pavel Akhtyamov on 26/03/2018.
//

#include <fstream>
#include <sstream>
#include "JsonStorage.h"
#include <boost/algorithm/string.hpp>


void JsonStorage::Read(const std::string &filename) {
  std::ifstream stream(filename);

  std::string buffer;
  while(std::getline(stream, buffer)) {
    if (buffer == "{") {
      continue;
    } else if (buffer == "}") {
      continue;
    } else {
      boost::algorithm::trim(buffer);
      std::stringstream tokenizer;
      tokenizer << buffer;
      std::string key;
      std::string value;
      tokenizer >> key >> value;
      key = key.substr(1, key.length() - 3);
      if (value[value.length() - 1] == ',') {
        value = value.substr(1, value.length() - 3);
      } else {
        value = value.substr(1, value.length() - 2);
      }
      pairs_[key] = value;
    }
  }
  stream.close();
}


void JsonStorage::WriteJson(const std::string &filename) {
  std::ofstream stream(filename);

  stream << "{" << "\n";
  for (auto it = pairs_.begin(); it != pairs_.end(); ++it) {
    auto iterator = *it;
    auto copy_iterator = it;
    ++copy_iterator;

    stream << "\t" << "\"" << iterator.first << "\": " << "\"" << iterator.second;
    if (copy_iterator == pairs_.end()) {
      stream << "\"\n";
    } else {
      stream << "\",\n";
    }
  }
  stream << "}" << "\n";
  stream.close();
}


void JsonStorage::SetData(const std::unordered_map<std::string, std::string> &pairs) {
  pairs_ = pairs;
}
