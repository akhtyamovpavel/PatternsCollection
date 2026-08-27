from __future__ import annotations

from .Axle import Axle


class CarAxle(Axle):
    """Машина ездит по плоскости, поэтому вверх и вниз не двигается."""

    STEP = 0.1

    def __init__(self) -> None:
        self._speed = 0.0
        self._move_angle = 0.0

    def accelerate(self, speed: float) -> None:
        self._speed += self.STEP

    def brake(self, speed: float) -> None:
        self._speed = max(0.0, self._speed - self.STEP)

    def move_left(self, angle: float) -> None:
        self._move_angle += self.STEP

    def move_right(self, angle: float) -> None:
        self._move_angle -= self.STEP

    def move_up(self, height: float) -> None:
        """Машина не летает, поэтому команда осмысленно ничего не делает."""

    def move_down(self, height: float) -> None:
        """То же самое: высоты у машины нет."""

    def beep(self) -> None:
        print("Beep")

    def print_info(self) -> None:
        print("Type: Car")
        print(f"Speed: {self._speed:.1f}")
        print(f"Angle: {self._move_angle:.1f}")
