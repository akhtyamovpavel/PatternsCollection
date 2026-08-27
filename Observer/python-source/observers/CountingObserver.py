from __future__ import annotations

from .Observer import Observer


class CountingObserver(Observer):
    """Ничего не печатает, только считает.

    Показывает, что подписчики независимы: источник один, а делают они разное
    и друг про друга не знают.
    """

    def __init__(self) -> None:
        self.count = 0

    def update(self, message: str) -> None:
        self.count += 1
