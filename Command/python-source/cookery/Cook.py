from __future__ import annotations

from typing import ClassVar


class Cook:
    """Исполнитель. Про команды не знает ничего и умеет только готовить."""

    RECIPES: ClassVar[dict[str, list[str]]] = {
        "Borsh": ["Boil water", "Crop vegetables", "Mix"],
        "Solyanka": ["Boil water", "Add meat", "Add mix of meat"],
    }

    def prepare(self, dish: str) -> None:
        steps = self.RECIPES.get(dish)
        if steps is None:
            print(f"Cook does not know how to make {dish}")
            return

        for step in steps:
            print(f"  {step}")
        print(f"  {dish} is ready")
