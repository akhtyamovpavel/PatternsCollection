from copy import copy

from FerrariPrototype import FerrariPrototype
from Prototype import Prototype


class PirelliFerrari(FerrariPrototype):
    def __init__(self, chassis_name: str, engine_name: str):
        super().__init__(engine_name)
        self.__chassis_name = chassis_name

    def __copy__(self) -> Prototype:
        prototype = copy(super())
        prototype.chassis_name = self.chassis_name
        return prototype

    def clone(self) -> Prototype:
        return copy(self)

    @property
    def chassis_name(self):
        return self.__chassis_name

    @chassis_name.setter
    def chassis_name(self, name):
        self.__chassis_name = name
