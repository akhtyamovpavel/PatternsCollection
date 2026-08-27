from Caretaker import Caretaker
from Originator import Originator


def main() -> None:
    game = Originator()
    caretaker = Caretaker(game)

    game.start_new_game()
    game.increase_level()
    print("before first save")
    game.show_current_progress()
    caretaker.save("first_save")

    game.increase_level()
    game.increase_level()
    print("after two more levels")
    game.show_current_progress()
    caretaker.save("second_save")

    print("saves:", sorted(caretaker.get_saves()))

    caretaker.load("first_save")
    print("after loading first save")
    game.show_current_progress()


if __name__ == "__main__":
    main()
