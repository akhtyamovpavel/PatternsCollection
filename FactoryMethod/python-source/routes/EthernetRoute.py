from __future__ import annotations
from .Route import Route


class EthernetRoute(Route):
    def connect(self) -> str:
        return 'Connected via Ethernet'
