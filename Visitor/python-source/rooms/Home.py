from __future__ import annotations

from typing import TYPE_CHECKING

from .ElementRoom import ElementRoom

if TYPE_CHECKING:
    from workers import Visitor


class Home(ElementRoom):
    """Дом это тоже комната, только он состоит из других комнат.

    Здесь видно, как посетитель и компоновщик работают вместе: дом пускает
    гостя к себе, а потом проводит его по всем комнатам.
    """

    def __init__(self) -> None:
        super().__init__()
        self._rooms: list[ElementRoom] = []

    def add(self, room: ElementRoom) -> Home:
        self._rooms.append(room)
        return self

    def accept(self, visitor: Visitor) -> None:
        visitor.visit_home(self)
        for room in self._rooms:
            room.accept(visitor)

    def get_name(self) -> str:
        return "Home"
