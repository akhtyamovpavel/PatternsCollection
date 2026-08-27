from behaviours import DuckHuntFlyBehaviour
from behaviours import SimpleFlyBehaviour
from behaviours import SimpleQuackBehaviour
from behaviours import SimpleSwimBehaviour
from Duck import Duck


def main() -> None:
    duck = Duck()
    duck.set_fly_behaviour(SimpleFlyBehaviour())
    duck.set_quack_behaviour(SimpleQuackBehaviour())
    duck.set_swim_behaviour(SimpleSwimBehaviour())
    duck.fly()
    duck.quack()
    duck.swim()

    print()

    # Тот же класс утки, другое поведение полёта. Ни одного нового наследника.
    duck_hunt = Duck()
    duck_hunt.set_fly_behaviour(DuckHuntFlyBehaviour())
    duck_hunt.set_quack_behaviour(SimpleQuackBehaviour())
    duck_hunt.fly()
    duck_hunt.quack()

    print()

    # Поведение можно заменить и во время работы: утка устала убегать.
    duck_hunt.set_fly_behaviour(SimpleFlyBehaviour())
    duck_hunt.fly()


if __name__ == "__main__":
    main()
