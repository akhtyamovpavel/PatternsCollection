from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class DishComponent(ABC):
    """Общий вид части рациона.

    Ради этого класса паттерн и существует: снаружи молоко и завтрак из десяти
    блюд выглядят одинаково, и калории у них спрашиваются одним способом.
    """

    @abstractmethod
    def get_calories(self) -> int:
        raise NotImplementedError
