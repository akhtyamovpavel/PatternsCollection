from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class QuackBehaviour(ABC):
    """Одна ось поведения утки, вынесенная из самой утки.

    Смысл стратегии в том, что поведение хранится рядом, а не наследуется.
    Утка одна, а плавать, летать и крякать она может по-разному, и сочетания
    складываются во время работы, а не при написании кода.
    """

    @abstractmethod
    def execute(self) -> None:
        raise NotImplementedError
