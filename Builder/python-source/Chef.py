from base.Burger import Burger
from builders.BurgerBuilder import BurgerBuilder


class Chef(object):
    def __init__(self):
        self.builder: BurgerBuilder

    def set_builder(self, builder: BurgerBuilder):
        self.builder = builder

    def cook(self) -> Burger:
        self.builder.reset()
        self.builder.add_low_bread()
        self.builder.add_vegetable()
        self.builder.add_meat()
        self.builder.add_vegetable()
        self.builder.add_high_bread()
        return self.builder.get_burger()
