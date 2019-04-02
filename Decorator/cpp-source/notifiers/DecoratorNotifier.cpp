//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#include <DecoratorNotifier.h>

DecoratorNotifier::DecoratorNotifier(std::shared_ptr<Notifier> notifier): notifier_(std::move(notifier)) {}

void DecoratorNotifier::Notify(const std::string &message) {
  notifier_->Notify(message);
}
