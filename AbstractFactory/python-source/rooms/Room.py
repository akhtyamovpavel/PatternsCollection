from abc import ABC
from abc import abstractmethod


class Room(ABC):
    @abstractmethod
    def generate_boss(self) -> str:
        pass
