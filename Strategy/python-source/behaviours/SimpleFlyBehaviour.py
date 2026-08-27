from __future__ import annotations

from .FlyBehaviour import FlyBehaviour


class SimpleFlyBehaviour(FlyBehaviour):
    def execute(self) -> None:
        print("Duck is flying")
