from __future__ import annotations

from typing import TYPE_CHECKING

from .Visitor import Visitor

if TYPE_CHECKING:
    from rooms import BathRoom
    from rooms import Home
    from rooms import Kitchen
    from rooms import LivingRoom


class Painter(Visitor):
    """Маляр: красит стены и потолки, пол не трогает."""

    def visit_kitchen(self, kitchen: Kitchen) -> None:
        kitchen.ceiling.color = "white"

    def visit_living_room(self, living_room: LivingRoom) -> None:
        living_room.wall.color = "beige"
        living_room.ceiling.color = "white"

    def visit_bath_room(self, bath_room: BathRoom) -> None:
        bath_room.ceiling.color = "white"

    def visit_home(self, home: Home) -> None:
        print("Painter came to the house")
