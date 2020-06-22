from abc import ABC, abstractmethod


class Room(ABC):
    @abstractmethod
    def generate_boss(self) -> str:
        pass
