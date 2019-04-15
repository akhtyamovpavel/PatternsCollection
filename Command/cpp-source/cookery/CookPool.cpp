//
// Created by Pavel Akhtyamov on 2019-04-15.
//

#include "CookPool.h"

std::shared_ptr<Cook> CookPool::GetCook() {
  if (!cook_) {
    cook_ = std::make_shared<Cook>();
  }
  return cook_;
}

std::shared_ptr<Cook> CookPool::cook_ = nullptr;
std::shared_ptr<Barman> CookPool::barman_ = nullptr;


std::shared_ptr<Barman> CookPool::GetBarman() {
  if (!barman_) {
    barman_ = std::make_shared<Barman>();
    return barman_;
  }
}
