//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#include <tgbot/tgbot.h>
#include <inicpp/inicpp.h>

#include <sstream>
#include <string>
#include <iostream>
#include <memory>
#include <Notifier.h>
#include <LogNotifier.h>
#include <TgNotifier.h>
#include <EmailNotifier.h>

int main() {
  inicpp::config config = inicpp::parser::load_file("configs/config.ini");

  std::shared_ptr<Notifier> notifier = std::make_shared<LogNotifier>("file.log");

  std::shared_ptr<TgNotifier> tg_notifier = std::make_shared<TgNotifier>(notifier);
  tg_notifier->Initialize(config["chat"]);

  std::shared_ptr<EmailNotifier> email_notifier = std::make_shared<EmailNotifier>(
      std::dynamic_pointer_cast<Notifier>(tg_notifier)
  );

  email_notifier->Initialize(config["email"]);

  email_notifier->Notify("Hello, TP");
  return 0;
}
