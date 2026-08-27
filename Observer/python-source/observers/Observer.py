from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class Observer(ABC):
    """Тот, кого уведомляют об изменении.

    Наблюдатель ничего не спрашивает сам. Источник сообщает ему, что произошло,
    и потому источник не зависит от того, сколько подписчиков и что они делают.
    """

    @abstractmethod
    def update(self, message: str) -> None:
        raise NotImplementedError
