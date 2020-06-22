//
// Created by Pavel Akhtyamov on 2019-04-09.
//
#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <mutex>

struct MessageStorage {
  std::queue<std::string> messages;
  std::mutex mutex;

  void ReadMessages() {
    while (true) {
      std::lock_guard<std::mutex> guard(mutex);

      while (!messages.empty()) {
        std::cout << "World " << messages.front() << std::endl;
        messages.pop();
      }
    }
  }

  void PushMessage(std::string message) {
    std::lock_guard<std::mutex> guard(mutex);
    messages.push(message);
  }
};


struct Player {
  std::shared_ptr<MessageStorage> storage;

  void SendMessage(std::string message) {
    storage->PushMessage(message);
  }
};

struct World {
  std::shared_ptr<MessageStorage> storage;
  std::vector<Player> players;

  void Subscribe(Player& player) {
    player.storage = storage;
    players.push_back(player);
  }
};


void ProcessMessages(Player& player) {
  while (true) {
    std::string message;
    std::cin >> message;

    player.SendMessage(message);
  }
}

int main() {
  MessageStorage m;

  World w;
  w.storage = std::shared_ptr<MessageStorage>(&m);
  Player p1; // Editor
  Player p2; // Listener

  w.Subscribe(p1);
  w.Subscribe(p2);

  std::thread t1(&MessageStorage::ReadMessages, &m);
  std::thread t2(ProcessMessages, std::ref(p1));
  t1.join();
  t2.join();
}