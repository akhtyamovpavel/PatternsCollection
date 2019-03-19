#include <iostream>
#include "TextStorage.h"
#include "JsonStorage.h"
#include "TextJsonAdapter.h"

int main() {
  TextStorage interface;

  interface.Read("data/input.txt");
  interface.Write("data/output.txt");

  JsonStorage storage;
  storage.Read("data/input.json");
  storage.WriteJson("data/output.json");

  TextJsonAdapter adapter;
  adapter.Read("data/input.txt");
  adapter.Write("data/output_text.json");
  return 0;
}