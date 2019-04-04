//
// Created by Pavel Akhtyamov on 2019-04-02.
//

#pragma once

#include <Notifier.h>
#include <memory>


class DecoratorNotifier : public Notifier {
 public:
  explicit DecoratorNotifier(std::shared_ptr<Notifier> notifier);
  virtual void Notify(const std::string &message);
  virtual ~DecoratorNotifier() = default;
 private:
  std::shared_ptr<Notifier> notifier_;
};



