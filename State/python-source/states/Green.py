from __future__ import annotations

from typing import TYPE_CHECKING

from .State import State

if TYPE_CHECKING:
    from TrafficLight import TrafficLight


class Green(State):
    def switch(self, light: TrafficLight) -> None:
        from .Yellow import Yellow

        light.set_state(Yellow())
        light.set_direction(light.TO_RED)

    def get_string_state(self) -> str:
        return "Green"
