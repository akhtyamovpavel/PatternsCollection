from __future__ import annotations

from .DecoratorNotifier import DecoratorNotifier
from .Notifier import Notifier


class EmailNotifier(DecoratorNotifier):
    """Добавляет отправку письмом поверх вложенного отправителя."""

    def __init__(self, notifier: Notifier, address: str = "team@example.com") -> None:
        super().__init__(notifier)
        self._address = address

    def notify(self, message: str) -> None:
        super().notify(message)
        print(f"[email to={self._address}] {message}")
