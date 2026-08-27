from __future__ import annotations

from typing import ClassVar


class Bartender:
    """Второй исполнитель. Тоже ничего не знает про команды."""

    RECIPES: ClassVar[dict[str, list[str]]] = {
        "Mojito": ["Crush mint", "Add lime", "Add rum", "Add soda"],
        "Americano": ["Pour espresso", "Add water"],
    }

    def mix(self, drink: str) -> None:
        steps = self.RECIPES.get(drink)
        if steps is None:
            print(f"Bartender does not know how to make {drink}")
            return

        for step in steps:
            print(f"  {step}")
        print(f"  {drink} is ready")
