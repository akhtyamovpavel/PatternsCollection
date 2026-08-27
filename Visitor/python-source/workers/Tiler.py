from __future__ import annotations

from typing import TYPE_CHECKING

from .Visitor import Visitor

if TYPE_CHECKING:
    from rooms import BathRoom
    from rooms import Home
    from rooms import Kitchen
    from rooms import LivingRoom


class Tiler(Visitor):
    """Плиточник: кладёт плитку там, где она уместна."""

    def visit_kitchen(self, kitchen: Kitchen) -> None:
        kitchen.floor.material = "tile"
        kitchen.wall.material = "tile"

    def visit_living_room(self, living_room: LivingRoom) -> None:
        """В гостиной плитка не нужна, и рабочий честно ничего не делает."""

    def visit_bath_room(self, bath_room: BathRoom) -> None:
        bath_room.floor.material = "tile"
        bath_room.wall.material = "tile"
        bath_room.ceiling.material = "tile"

    def visit_home(self, home: Home) -> None:
        print("Tiler came to the house")
