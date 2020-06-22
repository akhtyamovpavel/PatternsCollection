from routes import Route


class ThreeRoute(Route):
    def connect(self) -> str:
        return 'Connected via 3g'
