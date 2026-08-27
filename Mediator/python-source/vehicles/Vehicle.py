from __future__ import annotations

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from dispatcher import Dispatcher


class Vehicle:
    """Участник, который общается только через посредника.

    Ключевое здесь то, чего нет: у самолёта нет ссылок на другие самолёты. Он
    знает лишь диспетчера, и потому добавление десятого самолёта не меняет ни
    одного из девяти существующих.
    """

    def __init__(self, name: str) -> None:
        self.name = name
        self._dispatcher: Dispatcher | None = None

    def set_dispatcher(self, dispatcher: Dispatcher) -> None:
        self._dispatcher = dispatcher

    def notify(self, message: str) -> bool:
        if self._dispatcher is None:
            raise ValueError(f"{self.name} has no dispatcher")
        return self._dispatcher.notify(self, message)
