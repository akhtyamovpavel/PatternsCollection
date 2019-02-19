from __future__ import annotations
from abc import ABC, abstractmethod


class Route(ABC):

    @abstractmethod
    def connect(self) -> str:
        pass
