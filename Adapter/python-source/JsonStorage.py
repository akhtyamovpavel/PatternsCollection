import json


class JsonStorage:
    def read(self, filename):
        with open(filename, 'r') as fp:
            self.pairs = json.load(fp)

    def write_json(self, filename):
        with open(filename, 'w') as fp:
            json.dump(self.pairs, fp, indent=4, sort_keys=True)

    @property
    def data(self):
        return self.pairs

    @data.setter
    def data(self, value):
        self.pairs = value
