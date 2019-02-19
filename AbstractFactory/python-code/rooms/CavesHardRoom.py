from random import random

from rooms.BasementHardRoom import BasementHardRoom
from rooms.HardRoom import HardRoom
from rooms.Room import Room


class CavesHardRoom(HardRoom):
    def generate_loot(self) -> str:
        return 'Loot x4'

    def generate_boss(self) -> str:
        return '400hp'

    def generate_secret(self, previous_room: Room):
        if isinstance(previous_room, CavesHardRoom):
            return random() < 0.5
        if isinstance(previous_room, BasementHardRoom):
            return random() < 0.4
        return random() < 0.3
