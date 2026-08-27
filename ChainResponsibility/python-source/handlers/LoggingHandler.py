from __future__ import annotations

from abc import ABC
from abc import abstractmethod

from .Log import Log


class LoggingHandler(ABC):
    """Звено цепочки.

    Смысл паттерна в том, что отправитель не знает, кто именно обработает
    запрос. Он отдаёт его первому звену, а дальше запрос идёт по цепочке, пока
    кто-нибудь не возьмёт его или пока звенья не кончатся.
    """

    @abstractmethod
    def set_next(self, handler: LoggingHandler) -> LoggingHandler:
        raise NotImplementedError

    @abstractmethod
    def handle(self, log: Log) -> None:
        raise NotImplementedError
