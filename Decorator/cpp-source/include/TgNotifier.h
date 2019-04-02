//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#pragma once

#include <DecoratorNotifier.h>
#include <tgbot/Bot.h>
#include <inicpp/inicpp.h>

class TgNotifier : public DecoratorNotifier {
 public:
  explicit TgNotifier(std::shared_ptr<Notifier> notifier);
  void Initialize(const inicpp::section& section);
  void Notify(const std::string &message) override;
  virtual ~TgNotifier() override = default;
 private:
  int64_t chat_id_;
  std::string token_;
};



