from abc import ABC, abstractmethod

from rooms.Room import Room


class HardRoom(Room):
    @abstractmethod
    def generate_loot(self) -> str:
        pass

    @abstractmethod
    def generate_secret(self, previous_room: Room):
        pass