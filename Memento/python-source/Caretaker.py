from __future__ import annotations

from Originator import Originator

from Memento import Memento


class Caretaker:
    """Смотритель: хранит сохранения и не знает, что внутри них.

    Он умеет только две вещи: попросить хозяина сделать снимок и отдать снимок
    обратно. Ни одного обращения к полям состояния здесь нет и быть не должно.
    """

    def __init__(self, originator: Originator) -> None:
        self._originator = originator
        self._mementos: dict[str, Memento] = {}

    def save(self, save_name: str) -> None:
        self._mementos[save_name] = self._originator.save(save_name)

    def load(self, save_name: str) -> None:
        memento = self._mementos.get(save_name)
        if memento is None:
            raise KeyError(f"save not found: {save_name}")
        self._originator.restore(memento)

    def get_saves(self) -> set[str]:
        return set(self._mementos)
