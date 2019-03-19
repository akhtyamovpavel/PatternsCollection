//
// Created by Pavel Akhtyamov on 26/03/2018.
//

#pragma once

#include <string>
#include <vector>


struct KeyValuePair {
  std::string key;
  std::string value;
};


class TextStorage {
 public:
  void Read(const std::string& filename);
  virtual void Write(const std::string &filename);
  KeyValuePair ParseTokens(const std::string& input_string);

  std::vector<KeyValuePair> GetPairs() const;
 private:
  std::vector<KeyValuePair> pairs_;
};
