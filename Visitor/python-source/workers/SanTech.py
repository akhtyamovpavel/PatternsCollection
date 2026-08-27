from __future__ import annotations

from typing import TYPE_CHECKING

from .Visitor import Visitor

if TYPE_CHECKING:
    from rooms import BathRoom
    from rooms import Home
    from rooms import Kitchen
    from rooms import LivingRoom


class SanTech(Visitor):
    """Сантехник: работает только там, где есть вода."""

    def visit_kitchen(self, kitchen: Kitchen) -> None:
        print("  SanTech installs a sink in the kitchen")

    def visit_living_room(self, living_room: LivingRoom) -> None:
        """В гостиной воды нет."""

    def visit_bath_room(self, bath_room: BathRoom) -> None:
        print("  SanTech installs a bath and a sink")

    def visit_home(self, home: Home) -> None:
        print("SanTech came to the house")
