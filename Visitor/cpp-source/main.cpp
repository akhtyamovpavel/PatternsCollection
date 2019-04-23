//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "rooms/BathRoom.h"
#include "rooms/Kitchen.h"
#include "rooms/LivingRoom.h"
#include "workers/Tiler.h"
#include "workers/Painter.h"

int main() {
  BathRoom bath_room;
  Kitchen kitchen;
  LivingRoom living_room;

  Tiler tiler;

  kitchen.Accept(&tiler);

  bath_room.ShowDecorations();
  kitchen.ShowDecorations();
  living_room.ShowDecorations();

  Painter painter;
  kitchen.Accept(&painter);
  living_room.Accept(&painter);

  kitchen.ShowDecorations();
  living_room.ShowDecorations();

}