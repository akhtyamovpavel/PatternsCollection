from __future__ import annotations

from .FlyBehaviour import FlyBehaviour


class DuckHuntFlyBehaviour(FlyBehaviour):
    """Утка из игры летает иначе, и утка про такое отличие не знает."""

    def execute(self) -> None:
        print("Duck is flying away from the hunter")
