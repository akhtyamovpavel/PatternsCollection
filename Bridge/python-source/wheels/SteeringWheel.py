from __future__ import annotations

import sys
from abc import ABC
from abc import abstractmethod
from pathlib import Path

if str(Path(__file__).resolve().parents[1]) not in sys.path:
    sys.path.append(str(Path(__file__).resolve().parents[1]))

from axles import Axle


class SteeringWheel(ABC):
    """Абстракция: орган управления.

    Это вторая ось изменений. Мост нужен именно потому, что осей две: виды
    техники растут отдельно от видов пультов. При наследовании по обеим осям
    классов было бы произведение, а не сумма: два пульта на два вида техники
    дают четыре класса, три на три уже девять.

    Реализация передаётся в конструктор и живёт рядом, а не наследуется.
    """

    def __init__(self, axle: Axle) -> None:
        self._axle = axle

    @abstractmethod
    def push_wheel(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def pull_wheel(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def press_gas_pedal(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def press_brake_pedal(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def press_left_button(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def press_right_button(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def press_up_button(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def press_down_button(self) -> None:
        raise NotImplementedError

    def print_info(self) -> None:
        """Одинаково для всех пультов, поэтому объявлено здесь целиком."""
        self._axle.print_info()
