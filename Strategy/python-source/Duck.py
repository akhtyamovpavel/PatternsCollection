from __future__ import annotations

from behaviours import FlyBehaviour
from behaviours import QuackBehaviour
from behaviours import SwimBehaviour


class Duck:
    """Утка держит поведения, а не наследует их.

    Если бы поведения были в наследниках, каждое новое сочетание требовало бы
    отдельного класса: два способа летать на два способа крякать дают четыре
    класса, три на три уже девять. Здесь сочетания собираются на месте.
    """

    def __init__(self) -> None:
        self._fly_behaviour: FlyBehaviour | None = None
        self._quack_behaviour: QuackBehaviour | None = None
        self._swim_behaviour: SwimBehaviour | None = None

    def set_fly_behaviour(self, behaviour: FlyBehaviour) -> None:
        self._fly_behaviour = behaviour

    def set_quack_behaviour(self, behaviour: QuackBehaviour) -> None:
        self._quack_behaviour = behaviour

    def set_swim_behaviour(self, behaviour: SwimBehaviour) -> None:
        self._swim_behaviour = behaviour

    def fly(self) -> None:
        self._require(self._fly_behaviour, "fly").execute()

    def quack(self) -> None:
        self._require(self._quack_behaviour, "quack").execute()

    def swim(self) -> None:
        self._require(self._swim_behaviour, "swim").execute()

    @staticmethod
    def _require(behaviour, name: str):
        """Сообщаем понятной ошибкой, а не падаем на обращении к None."""
        if behaviour is None:
            raise ValueError(f"{name} behaviour is not set")
        return behaviour
