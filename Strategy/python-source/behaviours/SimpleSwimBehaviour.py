from __future__ import annotations

from .SwimBehaviour import SwimBehaviour


class SimpleSwimBehaviour(SwimBehaviour):
    def execute(self) -> None:
        print("Duck is swimming")
