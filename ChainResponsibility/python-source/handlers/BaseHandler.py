from __future__ import annotations

from collections.abc import Callable

from .Log import Log
from .LoggingHandler import LoggingHandler
from .LogLevel import LogLevel


class BaseHandler(LoggingHandler):
    """Общая часть звена: фильтр по уровню и передача дальше.

    Наследники переопределяют только process, то есть собственно работу.
    Обход цепочки и проверка уровня написаны здесь один раз.
    """

    def __init__(self, log_levels: set[LogLevel] | None = None) -> None:
        self._log_levels = log_levels or LogLevel.all()
        self._next: LoggingHandler | None = None
        self._on_error: Callable[[Exception, Log], None] | None = None

    def set_next(self, handler: LoggingHandler) -> LoggingHandler:
        """Возвращает переданное звено, чтобы цепочка собиралась в строку."""
        self._next = handler
        return handler

    def set_error_function(self, function: Callable[[Exception, Log], None]) -> None:
        self._on_error = function

    def handle(self, log: Log) -> None:
        if self._matches(log):
            try:
                self.process(log)
            except Exception as error:
                self._report(error, log)

        if self._next is not None:
            self._next.handle(log)

    def process(self, log: Log) -> None:
        """Работа звена. Базовое звено ничего не делает намеренно."""

    def _matches(self, log: Log) -> bool:
        return log.level in self._log_levels

    def _report(self, error: Exception, log: Log) -> None:
        if self._on_error is not None:
            self._on_error(error, log)
            return
        print(f"handler failed on {log}: {error}")
