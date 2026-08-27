from __future__ import annotations

from .Bartender import Bartender
from .Cook import Cook


class CookPool:
    """Отдаёт исполнителей. В настоящей системе на его месте был бы пул."""

    _cook = Cook()
    _bartender = Bartender()

    @classmethod
    def get_cook(cls) -> Cook:
        return cls._cook

    @classmethod
    def get_bartender(cls) -> Bartender:
        return cls._bartender
