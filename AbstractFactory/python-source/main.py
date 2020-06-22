from factories import RoomFactory
from factories.BasementFactory import BasementFactory
from factories.CavesFactory import CavesFactory
from rooms.HardRoom import HardRoom
from rooms.NormalRoom import NormalRoom


def main():
    basement_factory: RoomFactory = BasementFactory()

    normal_room: NormalRoom = basement_factory.create_normal_room()
    print(normal_room.generate_loot(), normal_room.generate_boss())

    hard_room: HardRoom = basement_factory.create_hard_room()
    print(hard_room.generate_loot(), hard_room.generate_boss())

    new_hard_room: HardRoom = basement_factory.create_hard_room()
    print('Secret:', new_hard_room.generate_secret(hard_room))

    caves_factory: RoomFactory = CavesFactory()

    caves_normal_room: NormalRoom = caves_factory.create_normal_room()
    print(caves_normal_room.generate_loot(), caves_normal_room.generate_boss())

    caves_hard_room: HardRoom = caves_factory.create_hard_room()
    print('Secret: ', caves_hard_room.generate_secret(caves_normal_room))


if __name__ == '__main__':
    main()
