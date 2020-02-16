//
// Created by Pavel Akhtyamov on 2019-04-24.
//

#include "SanTech.h"
#include "../rooms/Kitchen.h"
#include "../rooms/LivingRoom.h"
#include "../rooms/BathRoom.h"


void SanTech::visit(Kitchen *kitchen) {
  kitchen->wall.material = "sink";
}

void SanTech::visit(LivingRoom *living_room) {

}

void SanTech::visit(BathRoom *bath_room) {
  bath_room->wall.material = "bath";
}
