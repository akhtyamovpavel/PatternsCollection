from __future__ import annotations

import threading
from collections import deque

from .Subject import Subject


class MessageStorage(Subject):
    """Очередь сообщений, которая уведомляет подписчиков о каждом новом.

    Замок нужен потому, что класс рассчитан на несколько потоков: в примере
    сообщения кладут два разных потока сразу.
    """

    def __init__(self) -> None:
        super().__init__()
        self._messages: deque[str] = deque()
        self._lock = threading.Lock()

    def push_message(self, message: str) -> None:
        with self._lock:
            self._messages.append(message)
        self.notify(message)

    def read_messages(self) -> list[str]:
        with self._lock:
            messages = list(self._messages)
            self._messages.clear()
        return messages
