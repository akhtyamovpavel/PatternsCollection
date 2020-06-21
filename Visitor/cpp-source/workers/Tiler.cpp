//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#include "Tiler.h"
#include "../rooms/Kitchen.h"
#include "../rooms/BathRoom.h"
#include "../rooms/Home.h"

void Tiler::visit(Kitchen *kitchen) {
  Tile(&(kitchen->wall));
}

void Tiler::visit(LivingRoom *living_room) {

}

void Tiler::visit(BathRoom *bath_room) {
  Tile(&(bath_room->wall));
  Tile(&(bath_room->floor));
}

void Tiler::Tile(Surface* surface) {
  surface->material = "tile";
  surface->color = "white";
}

void Tiler::visit(Home *home) {
  home->bath_room_.Accept(this);
  home->kitchen_.Accept(this);
  home->living_room_.Accept(this);
}
