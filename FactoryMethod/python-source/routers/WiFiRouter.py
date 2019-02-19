from routers import Router
from routes import Route, WiFiRoute


class WiFiRouter(Router):
    def create_route(self) -> Route:
        return WiFiRoute()

