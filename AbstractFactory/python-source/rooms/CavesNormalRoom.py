from rooms.NormalRoom import NormalRoom


class CavesNormalRoom(NormalRoom):
    def generate_loot(self) -> str:
        return 'Loot x3'

    def generate_boss(self) -> str:
        return '300 hp'
