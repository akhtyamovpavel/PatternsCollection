from __future__ import annotations

from dataclasses import dataclass
from dataclasses import field


@dataclass(frozen=True)
class State:
    """Снимок состояния игры. Неизменяемый намеренно.

    Если снимок можно было бы поправить снаружи, он перестал бы быть снимком:
    сохранение перезаписывалось бы задним числом.
    """

    level: int = 0
    experience: int = 0
    inventory: tuple[str, ...] = field(default_factory=tuple)


@dataclass(frozen=True)
class Memento:
    """Хранитель: снимок плюс имя, под которым он сохранён.

    Смотритель хранит его целиком и внутрь не заглядывает. Это и есть граница:
    состояние принадлежит хозяину, а не тому, кто складывает сохранения.
    """

    name: str
    state: State
