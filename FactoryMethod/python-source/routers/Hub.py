from __future__ import annotations
from .Router import Router
from routes import Route, EthernetRoute


class Hub(Router):
    def create_route(self) -> Route:
        return EthernetRoute()
