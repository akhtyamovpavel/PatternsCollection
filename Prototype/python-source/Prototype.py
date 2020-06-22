from __future__ import annotations
from abc import abstractmethod


class Prototype:

    @abstractmethod
    def clone(self) -> Prototype:
        pass
