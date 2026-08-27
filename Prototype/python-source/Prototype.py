from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class Prototype(ABC):
    """Объект, который умеет копировать сам себя.

    Смысл в том, что копию делает сам объект, а не вызывающий. Вызывающему не
    нужно знать ни точный класс, ни список полей, ни то, какие из них надо
    копировать глубоко.
    """

    @abstractmethod
    def clone(self) -> Prototype:
        raise NotImplementedError
