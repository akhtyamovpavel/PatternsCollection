from __future__ import annotations

from abc import ABC
from abc import abstractmethod
from typing import TYPE_CHECKING

from .Surface import Surface

if TYPE_CHECKING:
    from workers import Visitor


class ElementRoom(ABC):
    """Комната, к которой может прийти рабочий.

    Метод accept здесь единственный обязательный, и он всегда написан одинаково:
    комната зовёт у гостя тот метод, который соответствует её типу. Такой приём
    называют двойной диспетчеризацией: выбор кода зависит и от типа комнаты, и
    от типа рабочего.
    """

    def __init__(self) -> None:
        self.wall = Surface()
        self.floor = Surface()
        self.ceiling = Surface()

    @abstractmethod
    def accept(self, visitor: Visitor) -> None:
        raise NotImplementedError

    @abstractmethod
    def get_name(self) -> str:
        raise NotImplementedError

    def show_decorations(self) -> None:
        print(f"{self.get_name()}:")
        print(f"  wall:    {self.wall}")
        print(f"  floor:   {self.floor}")
        print(f"  ceiling: {self.ceiling}")
