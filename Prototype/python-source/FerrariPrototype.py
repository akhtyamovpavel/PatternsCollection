from __future__ import annotations

from Prototype import Prototype


class FerrariPrototype(Prototype):
    def __init__(self, engine_name: str) -> None:
        self._engine_name = engine_name

    @property
    def engine_name(self) -> str:
        return self._engine_name

    def clone(self) -> FerrariPrototype:
        return FerrariPrototype(self._engine_name)

    def __str__(self) -> str:
        return f"Ferrari(engine={self._engine_name})"
