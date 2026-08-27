from __future__ import annotations

from .Observer import Observer


class ConsoleObserver(Observer):
    """Печатает каждое сообщение."""

    def __init__(self, name: str) -> None:
        self._name = name

    def update(self, message: str) -> None:
        print(f"{self._name} received: {message}")
