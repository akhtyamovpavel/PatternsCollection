//
// Created by Pavel Akhtyamov on 26/03/2018.
//

#pragma once
#include <string>
#include <unordered_map>

class JsonStorage {
 public:
  void Read(const std::string& filename);
  void WriteJson(const std::string& filename);
  void SetData(const std::unordered_map<std::string, std::string>& pairs);

 private:
  std::unordered_map<std::string, std::string> pairs_;
};

