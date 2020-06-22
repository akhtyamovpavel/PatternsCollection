from JsonStorage import JsonStorage
from TextStorage import TextStorage


class TextJsonAdapter(TextStorage):
    def __init__(self):
        super().__init__()
        self.json_storage = JsonStorage()

    def write(self, filename):
        pairs = self.convert_to_json()
        self.json_storage.data = pairs
        self.json_storage.write_json(filename)

    def convert_to_json(self):
        pairs = {}
        for pair in self.pairs:
            pairs[pair.key] = pair.value
        return pairs
