from __future__ import annotations

from .Axle import Axle


class PlaneAxle(Axle):
    """Самолёт умеет всё то же самое плюс высоту."""

    def __init__(self) -> None:
        self._speed = 0.0
        self._rotate_angle = 0.0
        self._height = 0.0

    def accelerate(self, speed: float) -> None:
        self._speed += speed

    def brake(self, speed: float) -> None:
        self._speed = max(0.0, self._speed - speed)

    def move_left(self, angle: float) -> None:
        self._rotate_angle += angle

    def move_right(self, angle: float) -> None:
        self._rotate_angle -= angle

    def move_up(self, height: float) -> None:
        self._height += height

    def move_down(self, height: float) -> None:
        self._height = max(0.0, self._height - height)

    def beep(self) -> None:
        print("Whoosh")

    def print_info(self) -> None:
        print("Type: Plane")
        print(f"Speed: {self._speed:.1f}")
        print(f"Angle: {self._rotate_angle:.1f}")
        print(f"Height: {self._height:.1f}")
