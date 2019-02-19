from random import random

from rooms import Room
from rooms.HardRoom import HardRoom


class BasementHardRoom(HardRoom):
    def generate_loot(self) -> str:
        return 'Loot x2'

    def generate_boss(self) -> str:
        return '200hp'

    def generate_secret(self, previous_room: Room) -> bool:
        if isinstance(previous_room, BasementHardRoom):
            return random() < 0.2
        else:
            return random() < 0.1
