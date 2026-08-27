from __future__ import annotations


class Burger:
    """Продукт, который собирает строитель."""

    def __init__(self, components: list[str]):
        self._components = components

    def __repr__(self) -> str:
        return '\n'.join([
            'Burger content:',
            '\n'.join(self._components),
        ])
