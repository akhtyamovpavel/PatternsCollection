from rooms import BathRoom
from rooms import Home
from rooms import Kitchen
from rooms import LivingRoom
from workers import Painter
from workers import SanTech
from workers import Tiler
from workers import Windower


def build_home() -> tuple[Home, list]:
    """Собирает дом и отдаёт вместе со списком комнат, чтобы показать результат."""
    rooms = [Kitchen(), LivingRoom(), BathRoom()]
    home = Home()
    for room in rooms:
        home.add(room)
    return home, rooms


def main() -> None:
    home, rooms = build_home()

    # Каждый рабочий обходит весь дом целиком: accept сам зовёт visit_home,
    # а потом проводит гостя по комнатам. Ни одна комната не знает, какие
    # рабочие вообще существуют.
    for worker in (Tiler(), Painter(), Windower(), SanTech()):
        home.accept(worker)
        print()

    print("что получилось:")
    for room in rooms:
        room.show_decorations()


if __name__ == "__main__":
    main()
