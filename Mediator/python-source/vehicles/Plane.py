from __future__ import annotations

from .PlaneCommands import PlaneCommand
from .Vehicle import Vehicle


class Plane(Vehicle):
    def __init__(self, name: str) -> None:
        super().__init__(name)
        self._status = PlaneCommand.CONNECTED

    def get_status(self) -> PlaneCommand:
        return self._status

    def land(self) -> None:
        """Просит полосу и садится, только если её дали."""
        self._status = PlaneCommand.WAITING
        print(f"{self.name}: requesting the runway")

        allowed = self.notify("request_landing")
        if not allowed:
            print(f"{self.name}: runway is busy, staying in the air")
            return

        self._status = PlaneCommand.LANDING
        print(f"{self.name}: landing")
        self.has_landed()

    def has_landed(self) -> None:
        self._status = PlaneCommand.LANDED
        print(f"{self.name}: landed")
        self.notify("runway_free")
