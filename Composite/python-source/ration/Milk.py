from __future__ import annotations

from .DishComponent import DishComponent


class Milk(DishComponent):
    """Лист дерева: внутри ничего нет, калории известны сразу."""

    CALORIES = 100

    def get_calories(self) -> int:
        return self.CALORIES
