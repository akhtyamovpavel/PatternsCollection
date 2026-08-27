from __future__ import annotations

from typing import TYPE_CHECKING

from .Visitor import Visitor

if TYPE_CHECKING:
    from rooms import BathRoom
    from rooms import Home
    from rooms import Kitchen
    from rooms import LivingRoom


class Windower(Visitor):
    """Оконщик: ставит окна там, где они бывают."""

    def visit_kitchen(self, kitchen: Kitchen) -> None:
        kitchen.wall.material = "brick with window"

    def visit_living_room(self, living_room: LivingRoom) -> None:
        living_room.wall.material = "brick with panoramic window"

    def visit_bath_room(self, bath_room: BathRoom) -> None:
        """В санузле окна не ставим."""

    def visit_home(self, home: Home) -> None:
        print("Windower came to the house")
