from __future__ import annotations

from commands import Command


class Waiter:
    """Тот, кто принимает заказ, но не готовит.

    Официант знает только про интерфейс команды. Кто исполнитель и что именно
    он сделает, официанту неизвестно, и в этом весь смысл: добавление нового
    блюда не меняет ни строчки здесь.

    Заодно официант ведёт счёт, и он возможен только потому, что команды это
    объекты, которые можно сохранить.
    """

    def __init__(self) -> None:
        self._commands: list[Command] = []

    def set_command(self, command: Command) -> None:
        self._commands.append(command)

    def execute_commands(self) -> None:
        for command in self._commands:
            print(f"Order: {command}")
            command.execute()

    def get_bill(self) -> int:
        return sum(command.get_price() for command in self._commands)

    def cancel_last(self) -> Command | None:
        """Отмена возможна ровно потому, что запрос стал объектом."""
        if not self._commands:
            return None
        return self._commands.pop()
