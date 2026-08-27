from FerrariPrototype import FerrariPrototype
from PirelliFerrari import PirelliFerrari

from Prototype import Prototype


def main() -> None:
    machines: list[Prototype] = [
        PirelliFerrari("Pirelli", "Ferrari"),
        FerrariPrototype("BMW"),
    ]

    # Вызывающий не знает классов и всё равно получает правильные копии.
    clones = [machine.clone() for machine in machines]

    for original, clone in zip(machines, clones, strict=True):
        print(f"{original}  ->  {clone}")
        print("  тот же объект:", original is clone)
        print("  тот же класс: ", type(original) is type(clone))


if __name__ == "__main__":
    main()
