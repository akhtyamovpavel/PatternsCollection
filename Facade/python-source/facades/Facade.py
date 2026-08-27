from __future__ import annotations

from .BurgerFacade import BurgerFacade
from .IsaacFacade import IsaacFacade


class Facade:
    """Фасад над двумя другими фасадами.

    Показывает, что фасады складываются: каждый следующий уровень убирает ещё
    часть подробностей. Наружу остаются три действия, за которыми стоят
    строители, повар, фабрики комнат и сами комнаты.
    """

    def __init__(self) -> None:
        self._isaac_facade = IsaacFacade()
        self._burger_facade = BurgerFacade()

    def create_normal_game(self) -> str:
        return self._isaac_facade.create_game("normal")

    def create_hard_game(self) -> str:
        return self._isaac_facade.create_game("hard")

    def create_vegiburger(self) -> str:
        return self._burger_facade.create_vegiburger()
