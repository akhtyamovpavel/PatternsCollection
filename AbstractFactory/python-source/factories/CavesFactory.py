from factories.RoomFactory import RoomFactory
from rooms.CavesHardRoom import CavesHardRoom
from rooms.CavesNormalRoom import CavesNormalRoom
from rooms.HardRoom import HardRoom
from rooms.NormalRoom import NormalRoom


class CavesFactory(RoomFactory):
    def create_normal_room(self) -> NormalRoom:
        return CavesNormalRoom()

    def create_hard_room(self) -> HardRoom:
        return CavesHardRoom()
