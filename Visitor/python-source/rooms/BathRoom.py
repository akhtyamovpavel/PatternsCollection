from __future__ import annotations

from typing import TYPE_CHECKING

from .ElementRoom import ElementRoom

if TYPE_CHECKING:
    from workers import Visitor


class BathRoom(ElementRoom):
    def accept(self, visitor: Visitor) -> None:
        visitor.visit_bath_room(self)

    def get_name(self) -> str:
        return "BathRoom"
