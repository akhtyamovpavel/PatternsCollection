//
// Created by Pavel Akhtyamov on 2020-02-16.
//


#include <memory>
#include <routers/Router.h>
#include <routers/Hub.h>
#include <iostream>
#include <routers/WifiRouter.h>

int main() {

  std::cout << "Connection via hub" << std::endl;
  std::shared_ptr<Router> hub = std::make_shared<Hub>();
  std::cout << hub->ConnectToNet() << std::endl;

  std::cout << "Connection via WiFi Router" << std::endl;
  std::shared_ptr<Router> wifi_router = std::make_shared<WifiRouter>();
  std::cout << wifi_router->ConnectToNet() << std::endl;

}