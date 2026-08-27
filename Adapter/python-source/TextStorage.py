import os
from collections import namedtuple

KeyValuePair = namedtuple('KeyValuePair', ['key', 'value'])


class TextStorage:
    def __init__(self):
        self.pairs: list[KeyValuePair] = []

    def read(self, filename):
        with open(filename) as fp:
            for line in fp:
                self.pairs.append(self.parse_tokens(line))

    def write(self, filename):
        with open(filename, 'w') as fp:
            fp.writelines(f'{pair.key} {pair.value}{os.linesep}' for pair in self.pairs)

    def parse_tokens(self, string: str) -> KeyValuePair:
        key, value = string.strip().split()

        return KeyValuePair(
            key=key,
            value=value
        )
