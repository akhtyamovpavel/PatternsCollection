from __future__ import annotations

from abc import ABC
from abc import abstractmethod


class Route(ABC):

    @abstractmethod
    def connect(self) -> str:
        pass
