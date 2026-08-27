from axles import CarAxle
from axles import PlaneAxle
from wheels import Gamepad
from wheels import PlaneWheel


def main() -> None:
    # Одна и та же техника управляется разными пультами, и наоборот.
    # Мост позволяет сочетать их без порождения класса на каждую пару.
    gamepad_car = Gamepad(CarAxle())
    gamepad_car.press_up_button()
    for _ in range(10):
        gamepad_car.press_gas_pedal()
        gamepad_car.press_down_button()
        gamepad_car.press_gas_pedal()
    gamepad_car.push_wheel()
    gamepad_car.print_info()

    print()

    wheel_plane = PlaneWheel(PlaneAxle())
    wheel_plane.pull_wheel()
    wheel_plane.press_gas_pedal()
    wheel_plane.press_left_button()
    wheel_plane.print_info()

    print()

    # Тот же геймпад, но управляет самолётом: пара собирается на месте.
    gamepad_plane = Gamepad(PlaneAxle())
    gamepad_plane.press_down_button()
    gamepad_plane.press_gas_pedal()
    gamepad_plane.print_info()


if __name__ == "__main__":
    main()
