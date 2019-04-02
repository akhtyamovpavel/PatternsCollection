//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#include <tgbot/tgbot.h>
#include <inicpp/inicpp.h>
#include <vmime/vmime.hpp>
#include <vmime/platforms/posix/posixHandler.hpp>

#include <sstream>
#include <string>
#include <iostream>
#include <memory>


using inicpp::string_ini_t;


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


static vmime::shared_ptr <vmime::net::session> session = vmime::net::session::create();

class AcceptEverythingVerifier : public vmime::security::cert::certificateVerifier {
 public:
  virtual void verify(const std::shared_ptr <vmime::security::cert::certificateChain>& chain, const std::string& hostname) {
    return;
  }
};

void SendEmail(const inicpp::section &email_section) {
  vmime::utility::url url("smtp://smtp.gmail.com");
  auto tr = session->getTransport(url);

  std::string from_email = email_section["from"].get<string_ini_t>();
  std::string to_email = email_section["to"].get<string_ini_t>();
  std::string password = email_section["password"].get<string_ini_t>();

  tr->setProperty("connection.tls", true);
  tr->setProperty("auth.username", from_email);
  tr->setProperty("auth.password", password);
  tr->setProperty("options.need-authentication", true);
  tr->setCertificateVerifier(std::make_shared<AcceptEverythingVerifier>());
  tr->connect();

  vmime::mailbox from(from_email);

  vmime::mailboxList to;
  to.appendMailbox(std::make_shared<vmime::mailbox>(to_email));

  vmime::string message_data = "Hello world\r\n";

  vmime::utility::inputStreamStringAdapter vis(message_data);

  tr->send(from, to, vis, message_data.length());
}


int main() {
  inicpp::config config = inicpp::parser::load_file("configs/config.ini");
  inicpp::section section = config["chat"];

  std::string token = ParseChatToken(section["token"]);
  std::cout << token << std::endl;

  int64_t chat_id = ParseChatId(config);
  TgBot::Bot bot(token);

  SendEmail(config["email"]);

  bot.getApi().sendMessage(chat_id, "Hello world!");

  return 0;
}