from __future__ import annotations

from .DishComponent import DishComponent


class Dish(DishComponent):
    """Узел дерева: держит части и складывает их калории.

    Важно, что части хранятся как DishComponent, а не как Dish или Milk. Узел
    не знает, лист перед ним или ещё один узел, и складывает одинаково.
    """

    def __init__(self) -> None:
        self._components: list[DishComponent] = []

    def add(self, component: DishComponent) -> Dish:
        """Возвращает себя, чтобы вызовы складывались в цепочку."""
        self._components.append(component)
        return self

    def get_calories(self) -> int:
        return sum(component.get_calories() for component in self._components)
