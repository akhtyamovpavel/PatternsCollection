//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "rooms/BathRoom.h"
#include "rooms/Kitchen.h"
#include "rooms/LivingRoom.h"
#include "workers/Tiler.h"
#include "workers/Painter.h"
#include "workers/Windower.h"
#include "workers/SanTech.h"

#include "rooms/Home.h"

int main() {
  Home home;

  SanTech sanTech;
  Tiler tiler;

  home.Accept(&sanTech);
  home.Accept(&tiler);
}