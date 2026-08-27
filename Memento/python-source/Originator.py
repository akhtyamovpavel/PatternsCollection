from __future__ import annotations

from Memento import Memento
from Memento import State


class Originator:
    """Хозяин состояния: игра.

    Только он умеет делать снимок и только он умеет из снимка восстановиться.
    Смотритель снаружи не может ни прочитать поля, ни собрать снимок сам.
    """

    LEVEL_EXPERIENCE = 100

    def __init__(self) -> None:
        self._state = State()

    def start_new_game(self) -> None:
        self._state = State(level=1, experience=0, inventory=("knife",))

    def increase_level(self) -> None:
        self._state = State(
            level=self._state.level + 1,
            experience=self._state.experience + self.LEVEL_EXPERIENCE,
            inventory=(*self._state.inventory, f"trophy-{self._state.level + 1}"),
        )

    def save(self, save_name: str) -> Memento:
        return Memento(name=save_name, state=self._state)

    def restore(self, memento: Memento) -> None:
        self._state = memento.state

    def show_current_progress(self) -> None:
        print(
            f"level={self._state.level} "
            f"experience={self._state.experience} "
            f"inventory={list(self._state.inventory)}"
        )
