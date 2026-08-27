from dispatcher import PlaneDispatcher
from vehicles import Plane


def main() -> None:
    dispatcher = PlaneDispatcher()

    first = Plane("SU-100")
    second = Plane("SU-200")

    dispatcher.add_plane(first)
    dispatcher.add_plane(second)

    # Первый занимает полосу и освобождает её, второй ждёт и садится следом.
    first.land()
    print()
    second.land()
    print()

    print("статусы:", first.get_status().value, second.get_status().value)


if __name__ == "__main__":
    main()
