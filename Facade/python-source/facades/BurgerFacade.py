from __future__ import annotations

import sys
from pathlib import Path

BUILDER_SOURCE = Path(__file__).resolve().parents[3] / "Builder" / "python-source"
if str(BUILDER_SOURCE) not in sys.path:
    sys.path.append(str(BUILDER_SOURCE))

from builders.BurgerBuilder import BurgerBuilder
from builders.HamburgerBuilder import HamburgerBuilder
from builders.VegiburgerBuilder import VegiburgerBuilder
from Chef import Chef


class BurgerFacade:
    """Прячет связку из повара и строителей за двумя понятными методами.

    Снаружи никто не знает ни про то, что бургер собирается по шагам, ни про
    порядок этих шагов. Наружу торчит одно: какой бургер приготовить.
    """

    def __init__(self) -> None:
        self._chef = Chef()

    def create_hamburger(self) -> str:
        return self._create(HamburgerBuilder())

    def create_vegiburger(self) -> str:
        return self._create(VegiburgerBuilder())

    def create_burger(self, burger_type: str) -> str:
        """Выбор по строке нужен фасаду для вызовов из конфигурации."""
        builders: dict[str, type[BurgerBuilder]] = {
            "hamburger": HamburgerBuilder,
            "vegiburger": VegiburgerBuilder,
        }
        builder_class = builders.get(burger_type)
        if builder_class is None:
            raise ValueError(f"unknown burger type: {burger_type}")
        return self._create(builder_class())

    def _create(self, builder: BurgerBuilder) -> str:
        self._chef.set_builder(builder)
        burger = self._chef.cook()
        return str(burger)
