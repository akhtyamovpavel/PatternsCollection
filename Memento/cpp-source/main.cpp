//
// Created by Pavel Akhtyamov on 2019-04-22.
//

#include "Originator.h"
#include "Caretaker.h"

#include <iostream>

int main() {
  memento::Originator game;
  memento::Caretaker caretaker(&game);

  game.StartNewGame();

  game.IncreaseLevel();
  std::cout << "Before first save" << std::endl;
  game.ShowCurrentProgress();
  caretaker.Save("first_save");

  game.IncreaseLevel();
  game.ShowCurrentProgress();

  caretaker.Save("second_save");


  for (const std::string& save_name : caretaker.GetSaves()) {
    std::cout << save_name << std::endl;
  }

  caretaker.Load("first_save");
  game.ShowCurrentProgress();

}