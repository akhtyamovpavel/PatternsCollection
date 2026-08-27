from __future__ import annotations

from abc import ABC
from abc import abstractmethod
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from vehicles import Vehicle


class Dispatcher(ABC):
    """Посредник: единственный, кто знает про всех участников сразу."""

    @abstractmethod
    def notify(self, vehicle: Vehicle, message: str) -> bool:
        raise NotImplementedError
