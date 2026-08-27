from __future__ import annotations

from FerrariPrototype import FerrariPrototype


class PirelliFerrari(FerrariPrototype):
    """Наследник копируется правильно, потому что копирует себя сам.

    Если бы копию делал вызывающий, он вызвал бы конструктор базового класса и
    молча потерял бы шасси. Здесь потерять его невозможно.
    """

    def __init__(self, chassis_name: str, engine_name: str) -> None:
        super().__init__(engine_name)
        self._chassis_name = chassis_name

    @property
    def chassis_name(self) -> str:
        return self._chassis_name

    def clone(self) -> PirelliFerrari:
        return PirelliFerrari(self._chassis_name, self.engine_name)

    def __str__(self) -> str:
        return f"PirelliFerrari(chassis={self._chassis_name}, engine={self.engine_name})"
