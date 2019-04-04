//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#pragma once

#include <Notifier.h>
#include <fstream>
#include <memory>


class LogNotifier : public Notifier {
 public:
  explicit LogNotifier(const std::string& filename);
  ~LogNotifier();

  void Notify(const std::string &message) override;
 private:

  std::ofstream stream_;
};



