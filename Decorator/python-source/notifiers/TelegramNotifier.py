from __future__ import annotations

from .DecoratorNotifier import DecoratorNotifier
from .Notifier import Notifier


class TelegramNotifier(DecoratorNotifier):
    """Добавляет отправку в мессенджер поверх вложенного отправителя.

    Настоящий клиент здесь заменён печатью: пример должен запускаться без
    внешних зависимостей и без ключей.
    """

    def __init__(self, notifier: Notifier, chat_id: str = "0") -> None:
        super().__init__(notifier)
        self._chat_id = chat_id

    def notify(self, message: str) -> None:
        super().notify(message)
        print(f"[telegram chat={self._chat_id}] {message}")
