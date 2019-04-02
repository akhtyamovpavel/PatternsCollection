//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#pragma once

#include <DecoratorNotifier.h>
#include <inicpp/section.h>
#include <vmime/vmime.hpp>

class EmailNotifier : public DecoratorNotifier {
 public:
  explicit EmailNotifier(std::shared_ptr<Notifier> notifier);
  void Notify(const std::string &message) override;
  void Initialize(const inicpp::section& section);
  ~EmailNotifier() override = default;
 private:
  std::string from_email_;
  std::string to_email_;
  std::string password_;
  std::shared_ptr<vmime::net::transport> transport_;
};



