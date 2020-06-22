from routers import Router
from routes import Route
from routes.FourRoute import FourRoute


class FourRouter(Router):

    def create_route(self) -> Route:
        return FourRoute()
