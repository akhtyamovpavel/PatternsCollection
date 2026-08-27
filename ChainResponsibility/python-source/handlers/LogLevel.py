from __future__ import annotations

from enum import Enum


class LogLevel(Enum):
    """Уровни записи. Каждый обработчик берёт себе только нужные."""

    DEBUG = "debug"
    INFO = "info"
    WARNING = "warning"
    ERROR = "error"

    @classmethod
    def all(cls) -> set[LogLevel]:
        return set(cls)

    @classmethod
    def problems(cls) -> set[LogLevel]:
        return {cls.WARNING, cls.ERROR}
