from __future__ import annotations

from pathlib import Path

from .BaseHandler import BaseHandler
from .Log import Log
from .LogLevel import LogLevel


class FileHandler(BaseHandler):
    """Пишет запись в файл."""

    def __init__(self, filename: str | Path, log_levels: set[LogLevel] | None = None) -> None:
        super().__init__(log_levels)
        self._path = Path(filename)

    def process(self, log: Log) -> None:
        with self._path.open("a", encoding="utf-8") as stream:
            stream.write(str(log) + "\n")
