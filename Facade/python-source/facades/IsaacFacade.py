from __future__ import annotations

import sys
from pathlib import Path

ABSTRACT_FACTORY_SOURCE = (
    Path(__file__).resolve().parents[3] / "AbstractFactory" / "python-source"
)
if str(ABSTRACT_FACTORY_SOURCE) not in sys.path:
    sys.path.append(str(ABSTRACT_FACTORY_SOURCE))

from factories.BasementFactory import BasementFactory
from factories.CavesFactory import CavesFactory
from factories.RoomFactory import RoomFactory


class IsaacFacade:
    """Прячет выбор фабрики и сборку комнаты за одним методом.

    Вызывающему не нужно знать, что за уровнем стоит своя фабрика и что комната
    умеет отдавать добычу и босса по отдельности.
    """

    def __init__(self) -> None:
        self._factories: dict[str, RoomFactory] = {
            "basement": BasementFactory(),
            "caves": CavesFactory(),
        }

    def create_game(self, difficulty: str, level: str = "basement") -> str:
        factory = self._factories.get(level)
        if factory is None:
            raise ValueError(f"unknown level: {level}")

        if difficulty == "hard":
            room = factory.create_hard_room()
        else:
            room = factory.create_normal_room()

        return f"{room.generate_loot()} {room.generate_boss()}"
