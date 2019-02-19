from rooms.NormalRoom import NormalRoom


class BasementNormalRoom(NormalRoom):
    def generate_loot(self) -> str:
        return 'Loot'

    def generate_boss(self) -> str:
        return '100hp'