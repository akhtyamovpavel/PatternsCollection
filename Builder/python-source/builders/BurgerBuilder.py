from abc import ABC, abstractmethod

from base.Burger import Burger


class BurgerBuilder(ABC):

    @abstractmethod
    def reset(self):
        pass

    @abstractmethod
    def add_low_bread(self):
        pass

    @abstractmethod
    def add_meat(self):
        pass

    @abstractmethod
    def add_high_bread(self):
        pass

    @abstractmethod
    def add_vegetable(self):
        pass

    @abstractmethod
    def get_burger(self) -> Burger:
        pass
