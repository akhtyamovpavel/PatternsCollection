from __future__ import annotations
from abc import ABC, abstractmethod

from rooms.Room import Room


class NormalRoom(Room):
    @abstractmethod
    def generate_loot(self) -> str:
        pass
