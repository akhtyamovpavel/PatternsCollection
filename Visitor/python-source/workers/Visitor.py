from __future__ import annotations

from abc import ABC
from abc import abstractmethod
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from rooms import BathRoom
    from rooms import Home
    from rooms import Kitchen
    from rooms import LivingRoom


class Visitor(ABC):
    """Рабочий, который приходит в дом.

    Паттерн нужен ровно тогда, когда новых операций больше, чем новых типов.
    Добавить маляра значит написать один класс и не трогать ни одной комнаты.
    Обратная сторона честная: добавить новую комнату значит дописать метод во
    все классы рабочих сразу.

    В C++ методы называются одинаково и различаются по типу аргумента. В Python
    перегрузки по типу нет, поэтому имена разные, а приём остаётся тем же.
    """

    @abstractmethod
    def visit_kitchen(self, kitchen: Kitchen) -> None:
        raise NotImplementedError

    @abstractmethod
    def visit_living_room(self, living_room: LivingRoom) -> None:
        raise NotImplementedError

    @abstractmethod
    def visit_bath_room(self, bath_room: BathRoom) -> None:
        raise NotImplementedError

    @abstractmethod
    def visit_home(self, home: Home) -> None:
        raise NotImplementedError
