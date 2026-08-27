from __future__ import annotations

from typing import TYPE_CHECKING

from .ElementRoom import ElementRoom

if TYPE_CHECKING:
    from workers import Visitor


class Kitchen(ElementRoom):
    def accept(self, visitor: Visitor) -> None:
        visitor.visit_kitchen(self)

    def get_name(self) -> str:
        return "Kitchen"
