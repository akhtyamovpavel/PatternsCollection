from __future__ import annotations

from .QuackBehaviour import QuackBehaviour


class SimpleQuackBehaviour(QuackBehaviour):
    def execute(self) -> None:
        print("Quack")
