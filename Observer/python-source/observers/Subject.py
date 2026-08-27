from __future__ import annotations

from .Observer import Observer


class Subject:
    """Источник событий. Держит подписчиков и рассылает им уведомления.

    Отписка нужна не для красоты: без неё источник держит ссылку на подписчика
    навсегда, и тот не освободится, даже когда больше не нужен.
    """

    def __init__(self) -> None:
        self._observers: list[Observer] = []

    def attach(self, observer: Observer) -> None:
        if observer not in self._observers:
            self._observers.append(observer)

    def detach(self, observer: Observer) -> None:
        if observer in self._observers:
            self._observers.remove(observer)

    def notify(self, message: str) -> None:
        # Идём по копии списка: подписчик имеет право отписаться прямо в update.
        for observer in list(self._observers):
            observer.update(message)
