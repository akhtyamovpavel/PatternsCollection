from typing import List


class Burger(object):
    def __init__(self, components: List[str]):
        self._components = components

    def __repr__(self):
        return '\n'.join([
            'Burger content:',
            '\n'.join([
                component for component in self._components
            ])
        ])
