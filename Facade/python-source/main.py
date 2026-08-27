from facades import Facade


def main() -> None:
    facade = Facade()

    print(facade.create_normal_game(), "is normal game")
    print(facade.create_hard_game(), "is hard game")
    print(facade.create_vegiburger(), "is burger")


if __name__ == "__main__":
    main()
