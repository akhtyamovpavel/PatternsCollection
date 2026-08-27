from __future__ import annotations

from .BaseHandler import BaseHandler
from .Log import Log


class DivisionZeroHandler(BaseHandler):
    """Звено, которое намеренно падает.

    Нужно, чтобы показать: сбой одного звена не рвёт цепочку. Остальные звенья
    отработают, а про ошибку сообщит заданная функция.
    """

    def process(self, log: Log) -> None:
        _ = 1 / 0
