from __future__ import annotations

from pathlib import Path

from .Notifier import Notifier


class LogNotifier(Notifier):
    """Основа цепочки: пишет сообщение в файл и никого не оборачивает."""

    def __init__(self, filename: str | Path) -> None:
        self._path = Path(filename)

    def notify(self, message: str) -> None:
        with self._path.open("a", encoding="utf-8") as stream:
            stream.write(message + "\n")
