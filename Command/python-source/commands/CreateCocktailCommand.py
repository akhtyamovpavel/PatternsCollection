from __future__ import annotations

import sys
from pathlib import Path
from typing import ClassVar

if str(Path(__file__).resolve().parents[1]) not in sys.path:
    sys.path.append(str(Path(__file__).resolve().parents[1]))

from cookery import Bartender

from .Command import Command


class CreateCocktailCommand(Command):
    PRICES: ClassVar[dict[str, int]] = {"Mojito": 480, "Americano": 200}

    def __init__(self, bartender: Bartender, drink: str) -> None:
        self._bartender = bartender
        self._drink = drink

    def execute(self) -> None:
        self._bartender.mix(self._drink)

    def get_price(self) -> int:
        return self.PRICES.get(self._drink, 0)

    def __str__(self) -> str:
        return f"cocktail: {self._drink}"
