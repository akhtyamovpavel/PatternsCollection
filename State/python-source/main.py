from TrafficLight import TrafficLight


def main() -> None:
    light = TrafficLight()

    for _ in range(10):
        light.print_state()
        light.change_color()


if __name__ == "__main__":
    main()
