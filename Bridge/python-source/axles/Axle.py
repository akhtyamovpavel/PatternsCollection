from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class Axle(ABC):
    """Реализация: то, что физически движется.

    Это одна из двух осей изменений. Добавление нового вида техники добавляет
    сюда одного наследника и не трогает органы управления.
    """

    @abstractmethod
    def accelerate(self, speed: float) -> None:
        raise NotImplementedError

    @abstractmethod
    def brake(self, speed: float) -> None:
        raise NotImplementedError

    @abstractmethod
    def move_left(self, angle: float) -> None:
        raise NotImplementedError

    @abstractmethod
    def move_right(self, angle: float) -> None:
        raise NotImplementedError

    @abstractmethod
    def move_up(self, height: float) -> None:
        raise NotImplementedError

    @abstractmethod
    def move_down(self, height: float) -> None:
        raise NotImplementedError

    @abstractmethod
    def beep(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def print_info(self) -> None:
        raise NotImplementedError
