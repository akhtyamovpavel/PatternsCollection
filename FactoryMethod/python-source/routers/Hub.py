from __future__ import annotations

from routes import EthernetRoute
from routes import Route

from .Router import Router


class Hub(Router):
    def create_route(self) -> Route:
        return EthernetRoute()
