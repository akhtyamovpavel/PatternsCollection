#include <utility>

//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#include <TgNotifier.h>
#include <sstream>
#include <tgbot/Bot.h>


std::string ParseChatToken(const inicpp::option& option) {
  std::stringstream buffer;
  bool first = true;
  for (auto &token: option.get_list<inicpp::string_ini_t>()) {
    if (!first) {
      buffer << ":";
    }
    first = false;
    buffer << token;
  }
  return buffer.str();
}


int64_t ParseChatId(const inicpp::section& section) {
  return section["chat_id"].get<inicpp::signed_ini_t>();
}


TgNotifier::TgNotifier(std::shared_ptr<Notifier> notifier) : DecoratorNotifier(std::move(notifier)) {}


void TgNotifier::Notify(const std::string &message) {
  DecoratorNotifier::Notify(message);
  TgBot::Bot bot(token_);
  bot.getApi().sendMessage(chat_id_, message);
}

void TgNotifier::Initialize(const inicpp::section& section) {
  token_ = ParseChatToken(section["token"]);
  chat_id_ = ParseChatId(section);
}

