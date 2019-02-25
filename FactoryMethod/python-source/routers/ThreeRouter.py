from routers import Router
from routes import Route
from routes.ThreeRoute import ThreeRoute


class ThreeRouter(Router):
    def create_route(self) -> Route:
        return ThreeRoute()