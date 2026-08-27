from __future__ import annotations

from .Notifier import Notifier


class DecoratorNotifier(Notifier):
    """Базовая обёртка: держит вложенный отправитель и передаёт ему вызов.

    Сама по себе она ничего не добавляет, и в этом смысл: наследники дописывают
    только своё поведение, а передачу дальше получают готовой.
    """

    def __init__(self, notifier: Notifier) -> None:
        self._notifier = notifier

    def notify(self, message: str) -> None:
        self._notifier.notify(message)
