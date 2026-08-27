from __future__ import annotations

from abc import ABC
from abc import abstractmethod
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from TrafficLight import TrafficLight


class State(ABC):
    """Одно состояние светофора.

    Смысл паттерна в том, что переход знает само состояние, а не хозяин. У
    светофора нет ни одного условия про цвета: он просто просит текущее
    состояние переключиться, а куда именно, решает состояние.
    """

    @abstractmethod
    def switch(self, light: TrafficLight) -> None:
        raise NotImplementedError

    @abstractmethod
    def get_string_state(self) -> str:
        raise NotImplementedError
