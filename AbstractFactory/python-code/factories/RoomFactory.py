from __future__ import annotations
from abc import ABC

from rooms.HardRoom import HardRoom
from rooms.NormalRoom import NormalRoom


class RoomFactory(ABC):
    def create_normal_room(self) -> NormalRoom:
        raise NotImplementedError

    def create_hard_room(self) -> HardRoom:
        raise NotImplementedError