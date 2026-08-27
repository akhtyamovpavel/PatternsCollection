from __future__ import annotations

from dataclasses import dataclass


@dataclass
class Surface:
    """Поверхность комнаты: из чего сделана и какого цвета."""

    material: str = "unknown"
    color: str = "unknown"

    def __str__(self) -> str:
        return f"{self.material}, {self.color}"
