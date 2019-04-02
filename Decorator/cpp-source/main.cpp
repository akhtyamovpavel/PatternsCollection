//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#include <tgbot/tgbot.h>
#include <inicpp/inicpp.h>

#include <sstream>
#include <string>
#include <iostream>



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

int64_t ParseChatId(const inicpp::config& config) {
  return config["chat"]["chat_id"].get<inicpp::signed_ini_t>();
}


int main() {
  inicpp::config config = inicpp::parser::load_file("configs/config.ini");
  inicpp::section section = config["chat"];

  std::string token = ParseChatToken(section["token"]);
  std::cout << token << std::endl;

  int64_t chat_id = ParseChatId(config);
  TgBot::Bot bot(token);

  bot.getApi().sendMessage(chat_id, "Hello world!");

  return 0;
}