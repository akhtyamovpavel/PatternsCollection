from __future__ import annotations

from .SteeringWheel import SteeringWheel


class PlaneWheel(SteeringWheel):
    """Штурвал: движение самого штурвала задаёт высоту."""

    STEP = 0.1

    def push_wheel(self) -> None:
        self._axle.move_down(self.STEP)

    def pull_wheel(self) -> None:
        self._axle.move_up(self.STEP)

    def press_gas_pedal(self) -> None:
        self._axle.accelerate(self.STEP)

    def press_brake_pedal(self) -> None:
        self._axle.brake(self.STEP)

    def press_left_button(self) -> None:
        self._axle.move_left(self.STEP)

    def press_right_button(self) -> None:
        self._axle.move_right(self.STEP)

    def press_up_button(self) -> None:
        self._axle.beep()

    def press_down_button(self) -> None:
        self._axle.beep()
