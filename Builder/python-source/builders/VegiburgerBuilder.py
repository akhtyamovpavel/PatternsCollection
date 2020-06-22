from base.Burger import Burger
from builders.BurgerBuilder import BurgerBuilder


class VegiburgerBuilder(BurgerBuilder):
    def __init__(self):
        super().__init__()
        self._contents = []

    def reset(self):
        self._contents = []

    def add_low_bread(self):
        self._contents.append('GrayLoaf')

    def add_meat(self):
        pass

    def add_high_bread(self):
        self._contents.append('BlackLoaf')

    def add_vegetable(self):
        self._contents.append('Salade')

    def get_burger(self) -> Burger:
        return Burger(self._contents)
