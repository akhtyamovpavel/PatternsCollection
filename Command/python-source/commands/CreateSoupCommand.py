from __future__ import annotations

import sys
from pathlib import Path
from typing import ClassVar

if str(Path(__file__).resolve().parents[1]) not in sys.path:
    sys.path.append(str(Path(__file__).resolve().parents[1]))

from cookery import Cook

from .Command import Command


class CreateSoupCommand(Command):
    """Знает исполнителя и то, что ему сказать. Больше ничего."""

    PRICES: ClassVar[dict[str, int]] = {"Borsh": 350, "Solyanka": 420}

    def __init__(self, cook: Cook, dish: str) -> None:
        self._cook = cook
        self._dish = dish

    def execute(self) -> None:
        self._cook.prepare(self._dish)

    def get_price(self) -> int:
        return self.PRICES.get(self._dish, 0)

    def __str__(self) -> str:
        return f"soup: {self._dish}"
