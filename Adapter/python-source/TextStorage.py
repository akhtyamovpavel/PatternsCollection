from collections import namedtuple
from typing import List

import os

KeyValuePair = namedtuple('KeyValuePair', ['key', 'value'])


class TextStorage:
    def __init__(self):
        self.pairs: List[KeyValuePair] = []

    def read(self, filename):
        with open(filename, 'r') as fp:
            for line in fp:
                self.pairs.append(self.parse_tokens(line))

    def write(self, filename):
        with open(filename, 'w') as fp:
            for pair in self.pairs:
                fp.write(f'{pair.key} {pair.value}{os.linesep}')

    def parse_tokens(self, string: str) -> KeyValuePair:
        key, value = string.strip().split()

        return KeyValuePair(
            key=key,
            value=value
        )
