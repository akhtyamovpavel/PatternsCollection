from ration import Breakfast
from ration import Dish
from ration import Milk


def main() -> None:
    # Дерево собирается цепочкой вызовов: завтрак с двумя стаканами молока,
    # и он же вместе с третьим стаканом становится частью всего рациона.
    breakfast = Breakfast().add(Milk()).add(Milk())
    ration = Dish().add(breakfast).add(Milk())

    print("breakfast calories:", breakfast.get_calories())
    print("ration calories:", ration.get_calories())

    # Обход одинаковый: и у листа, и у любого узла спрашиваем одно и то же.
    for component in (Milk(), breakfast, ration):
        print(type(component).__name__, "->", component.get_calories())


if __name__ == "__main__":
    main()
