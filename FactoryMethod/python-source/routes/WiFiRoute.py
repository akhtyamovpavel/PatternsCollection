from __future__ import annotations
from .Route import Route


class WiFiRoute(Route):
    def connect(self) -> str:
        return 'Connected via WiFi'
