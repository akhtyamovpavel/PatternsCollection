import threading

from observers import ConsoleObserver
from observers import CountingObserver
from observers import MessageStorage


def produce(storage: MessageStorage, prefix: str, amount: int) -> None:
    for index in range(amount):
        storage.push_message(f"{prefix}-{index}")


def main() -> None:
    storage = MessageStorage()

    console = ConsoleObserver("console")
    counter = CountingObserver()

    storage.attach(console)
    storage.attach(counter)

    first = threading.Thread(target=produce, args=(storage, "hello", 3))
    second = threading.Thread(target=produce, args=(storage, "world", 3))

    first.start()
    second.start()
    first.join()
    second.join()

    print()
    print("counter saw messages:", counter.count)

    # Отписываем печать: источник не меняется, а поведение меняется.
    storage.detach(console)
    storage.push_message("nobody prints this one")
    print("counter saw messages:", counter.count)

    print()
    print("в очереди осталось:", storage.read_messages())


if __name__ == "__main__":
    main()
