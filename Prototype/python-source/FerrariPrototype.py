from __future__ import annotations

from copy import copy

from Prototype import Prototype


class FerrariPrototype(Prototype):
    def __init__(self, engine_name: str):
        self.__engine_name = engine_name

    def __copy__(self) -> Prototype:
        copied_prototype = copy(super())
        copied_prototype.engine_name = self.engine_name
        return copied_prototype

    def clone(self) -> Prototype:
        return copy(self)  # using shallow copy for Prototype Pattern

    @property
    def engine_name(self):
        return self.__engine_name

    @engine_name.setter
    def engine_name(self, name):
        self.__engine_name = name
