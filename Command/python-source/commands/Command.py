from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class Command(ABC):
    """Запрос, ставший объектом.

    Ровно в этом смысл паттерна. Раз запрос это объект, его можно положить в
    список, передать другому, выполнить позже, повторить и сложить в историю.
    Вызов метода напрямую ничего из перечисленного не умеет.
    """

    @abstractmethod
    def execute(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def get_price(self) -> int:
        raise NotImplementedError

    @abstractmethod
    def __str__(self) -> str:
        raise NotImplementedError
