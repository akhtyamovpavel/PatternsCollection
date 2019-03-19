//
// Created by Pavel Akhtyamov on 26/03/2018.
//

#include <fstream>
#include <sstream>
#include "TextStorage.h"


void TextStorage::Read(const std::string &filename) {
  std::ifstream stream(filename);

  std::string buffer;
  while (std::getline(stream, buffer)) {
    pairs_.push_back(ParseTokens(buffer));
  }
  stream.close();
}


void TextStorage::Write(const std::string &filename) {
  std::ofstream stream(filename);

  for (auto &pair : pairs_) {
    stream << pair.key << " " << pair.value << "\n";
  }
  stream.close();
}


KeyValuePair TextStorage::ParseTokens(const std::string &input_string) {
  std::stringstream tokenizer;
  tokenizer << input_string;

  std::string key;
  std::string value;

  tokenizer >> key >> value;
  return { key, value };
}


std::vector<KeyValuePair> TextStorage::GetPairs() const {
  return pairs_;
}
