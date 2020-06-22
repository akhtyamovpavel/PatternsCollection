from JsonStorage import JsonStorage
from TextJsonAdapter import TextJsonAdapter
from TextStorage import TextStorage


if __name__ == '__main__':
    interface = TextStorage()

    interface.read('data/input.txt')
    interface.write('data/output.txt')

    storage = JsonStorage()
    storage.read('data/input.json')
    storage.write_json('data/output.json')

    adapter = TextJsonAdapter()
    adapter.read('data/input.txt')
    adapter.write('data/output_text.json')
