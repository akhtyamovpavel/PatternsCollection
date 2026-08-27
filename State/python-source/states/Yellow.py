from __future__ import annotations

from typing import TYPE_CHECKING

from .State import State

if TYPE_CHECKING:
    from TrafficLight import TrafficLight


class Yellow(State):
    """Жёлтый единственный, кому нужно направление.

    Из красного он ведёт в зелёный, из зелёного в красный, и без хранимого
    направления отличить эти два случая нельзя.
    """

    def switch(self, light: TrafficLight) -> None:
        from .Green import Green
        from .Red import Red

        if light.get_direction() == light.TO_GREEN:
            light.set_state(Green())
            return
        light.set_state(Red())

    def get_string_state(self) -> str:
        return "Yellow"
