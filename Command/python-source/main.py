from commands import CreateCocktailCommand
from commands import CreateSoupCommand
from cookery import CookPool
from Waiter import Waiter


def main() -> None:
    waiter = Waiter()

    waiter.set_command(CreateSoupCommand(CookPool.get_cook(), "Borsh"))
    waiter.set_command(CreateCocktailCommand(CookPool.get_bartender(), "Mojito"))
    waiter.set_command(CreateSoupCommand(CookPool.get_cook(), "Solyanka"))

    # Гость передумал: последний заказ снимаем до того, как что-то приготовлено.
    cancelled = waiter.cancel_last()
    print("cancelled:", cancelled)
    print()

    waiter.execute_commands()

    print()
    print("bill:", waiter.get_bill())


if __name__ == "__main__":
    main()
