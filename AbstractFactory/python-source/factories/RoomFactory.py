from __future__ import annotations
from abc import ABC

from rooms.HardRoom import HardRoom
from rooms.NormalRoom import NormalRoom


class RoomFactory(ABC):
    def create_normal_room(self) -> NormalRoom:
        pass

    # virtual NormalRoom* create_normal_room() = 0;

    def create_hard_room(self) -> HardRoom:
        pass

    # virtual HardRoom* create_hard_room() = 0;