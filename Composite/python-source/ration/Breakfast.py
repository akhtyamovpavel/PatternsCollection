from __future__ import annotations

from .Dish import Dish


class Breakfast(Dish):
    """Узел со своей добавкой к калориям.

    Показывает, что узел дерева может иметь собственное поведение сверх
    складывания частей: завтрак добавляет десять калорий на сервировку.
    """

    SERVING_CALORIES = 10

    def get_calories(self) -> int:
        return super().get_calories() + self.SERVING_CALORIES
