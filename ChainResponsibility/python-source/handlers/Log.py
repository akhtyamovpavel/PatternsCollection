from __future__ import annotations

from dataclasses import dataclass

from .LogLevel import LogLevel


@dataclass(frozen=True)
class Log:
    """Запись, которая идёт по цепочке."""

    level: LogLevel
    message: str

    def __str__(self) -> str:
        return f"[{self.level.value}] {self.message}"
