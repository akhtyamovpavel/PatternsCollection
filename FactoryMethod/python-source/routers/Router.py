from __future__ import annotations
from abc import ABC, abstractmethod

from routes import Route


class Router(ABC):
    @abstractmethod
    def create_route(self) -> Route:
        raise NotImplementedError

    def connect_to_net(self) -> str:
        route: Route = self.create_route()
        return route.connect()
