//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#include <EmailNotifier.h>
#include <memory>
#include <DecoratorNotifier.h>
#include <inicpp/config.h>

#include <vmime/vmime.hpp>
#include <vmime/platforms/posix/posixHandler.hpp>

using inicpp::string_ini_t;

static vmime::shared_ptr <vmime::net::session> session = vmime::net::session::create();

class AcceptEverythingVerifier : public vmime::security::cert::certificateVerifier {
 public:
  virtual void verify(const std::shared_ptr <vmime::security::cert::certificateChain>& chain, const std::string& hostname) {
    return;
  }
};


EmailNotifier::EmailNotifier(std::shared_ptr<Notifier> notifier) : DecoratorNotifier(notifier) {

}

void EmailNotifier::Notify(const std::string &message) {
  DecoratorNotifier::Notify(message);


  vmime::mailbox from(from_email_);

  vmime::mailboxList to;
  to.appendMailbox(std::make_shared<vmime::mailbox>(to_email_));

  vmime::string message_data = message + "\r\n";

  vmime::utility::inputStreamStringAdapter vis(message_data);

  transport_->send(from, to, vis, message_data.length());
}

void EmailNotifier::Initialize(const inicpp::section& section) {
  vmime::utility::url url("smtp://smtp.gmail.com");
  transport_ = session->getTransport(url);

  from_email_ = section["from"].get<string_ini_t>();
  to_email_ = section["to"].get<string_ini_t>();
  password_ = section["password"].get<string_ini_t>();

  transport_->setProperty("connection.tls", true);
  transport_->setProperty("auth.username", from_email_);
  transport_->setProperty("auth.password", password_);
  transport_->setProperty("options.need-authentication", true);
  transport_->setCertificateVerifier(std::make_shared<AcceptEverythingVerifier>());
  transport_->connect();
}
