from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class Notifier(ABC):
    """Общий вид отправителя уведомлений.

    Ради этого интерфейса паттерн и работает: обёртка снаружи выглядит так же,
    как то, что она обернула, поэтому обёртки складываются в цепочку любой
    длины и в любом порядке.
    """

    @abstractmethod
    def notify(self, message: str) -> None:
        raise NotImplementedError
