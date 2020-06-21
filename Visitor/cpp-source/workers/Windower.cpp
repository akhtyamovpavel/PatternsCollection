//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "Windower.h"
#include "../rooms/Kitchen.h"
#include "../rooms/BathRoom.h"
#include "../rooms/LivingRoom.h"
#include "../rooms/Home.h"


void Windower::visit(Kitchen *kitchen) {
  kitchen->wall.material = "window";
}

void Windower::visit(LivingRoom *living_room) {
  living_room->wall.material = "window";
  living_room->wall.color = "black";
}

void Windower::visit(BathRoom *bath_room) {

}

void Windower::visit(Home *home) {
  home->kitchen_.Accept(this);
  home->living_room_.Accept(this);
}
