from __future__ import annotations

from enum import Enum


class PlaneCommand(Enum):
    """Состояния самолёта в разговоре с диспетчером."""

    CONNECTED = "connected"
    WAITING = "waiting"
    LANDING = "landing"
    LANDED = "landed"
