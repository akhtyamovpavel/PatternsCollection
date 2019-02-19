from Chef import Chef
from builders.BurgerBuilder import BurgerBuilder
from builders.HamburgerBuilder import HamburgerBuilder
from builders.VegiburgerBuilder import VegiburgerBuilder


def main():
    chef: Chef = Chef()

    hamburger_builder: BurgerBuilder = HamburgerBuilder()
    chef.set_builder(hamburger_builder)
    print(chef.cook())

    vegiburger_builder: BurgerBuilder = VegiburgerBuilder()
    chef.set_builder(vegiburger_builder)
    print(chef.cook())


if __name__ == '__main__':
    main()
