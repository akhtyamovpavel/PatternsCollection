from rooms.BasementHardRoom import BasementHardRoom
from rooms.BasementNormalRoom import BasementNormalRoom
from rooms.HardRoom import HardRoom
from rooms.NormalRoom import NormalRoom

from factories.RoomFactory import RoomFactory


class BasementFactory(RoomFactory):
    def create_normal_room(self) -> NormalRoom:
        return BasementNormalRoom()

    def create_hard_room(self) -> HardRoom:
        return BasementHardRoom()
