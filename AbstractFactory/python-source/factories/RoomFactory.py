from __future__ import annotations

from abc import ABC
from abc import abstractmethod

from rooms.HardRoom import HardRoom
from rooms.NormalRoom import NormalRoom


class RoomFactory(ABC):
    """Абстрактная фабрика: создаёт семейство комнат одного уровня.

    Методы помечены абстрактными намеренно. Без пометки наследник, забывший их
    реализовать, молча вернул бы None, и ошибка всплыла бы далеко от причины.
    В C++ той же цели служит чисто виртуальный метод: `= 0` в объявлении.
    """

    @abstractmethod
    def create_normal_room(self) -> NormalRoom:
        raise NotImplementedError

    @abstractmethod
    def create_hard_room(self) -> HardRoom:
        raise NotImplementedError
