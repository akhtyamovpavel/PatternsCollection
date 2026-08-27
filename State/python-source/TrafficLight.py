from __future__ import annotations

from states import Red
from states import State


class TrafficLight:
    """Хозяин состояния. Про цвета не знает ничего.

    Обрати внимание, чего здесь нет: ни одного условия вида «если сейчас
    красный, то дальше жёлтый». Такие условия живут в самих состояниях, и
    добавление нового цвета не трогает этот класс.
    """

    TO_GREEN = "to_green"
    TO_RED = "to_red"

    def __init__(self) -> None:
        self._state: State = Red()
        self._direction = self.TO_GREEN

    def set_state(self, state: State) -> None:
        self._state = state

    def get_direction(self) -> str:
        return self._direction

    def set_direction(self, direction: str) -> None:
        self._direction = direction

    def change_color(self) -> None:
        self._state.switch(self)

    def print_state(self) -> None:
        print(self._state.get_string_state())
