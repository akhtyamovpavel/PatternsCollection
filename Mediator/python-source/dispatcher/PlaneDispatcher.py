from __future__ import annotations

import sys
from pathlib import Path

if str(Path(__file__).resolve().parents[1]) not in sys.path:
    sys.path.append(str(Path(__file__).resolve().parents[1]))

from vehicles import Vehicle

from .Dispatcher import Dispatcher


class PlaneDispatcher(Dispatcher):
    """Держит полосу и решает, кому её отдать.

    Вся логика взаимодействия собрана здесь. Если бы самолёты договаривались
    напрямую, каждому пришлось бы знать про остальных, и число связей росло бы
    как квадрат числа участников.
    """

    def __init__(self) -> None:
        self._planes: list[Vehicle] = []
        self._runway_taken_by: Vehicle | None = None

    def add_plane(self, plane: Vehicle) -> None:
        self._planes.append(plane)
        plane.set_dispatcher(self)

    def notify(self, vehicle: Vehicle, message: str) -> bool:
        if message == "request_landing":
            if self._runway_taken_by is None:
                self._runway_taken_by = vehicle
                print(f"  dispatcher: runway is given to {vehicle.name}")
                return True
            print(
                f"  dispatcher: runway is taken by "
                f"{self._runway_taken_by.name}, {vehicle.name} waits"
            )
            return False

        if message == "runway_free":
            if self._runway_taken_by is vehicle:
                self._runway_taken_by = None
                print(f"  dispatcher: runway is free again after {vehicle.name}")
            return True

        return False
