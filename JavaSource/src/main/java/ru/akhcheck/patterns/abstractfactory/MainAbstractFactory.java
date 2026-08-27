package ru.akhcheck.patterns.abstractfactory;

import ru.akhcheck.patterns.abstractfactory.factories.BasementFactory;
import ru.akhcheck.patterns.abstractfactory.factories.CavesFactory;
import ru.akhcheck.patterns.abstractfactory.factories.RoomFactory;
import ru.akhcheck.patterns.abstractfactory.rooms.HardRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.NormalRoom;

/** Точка входа примера абстрактной фабрики. */
public class MainAbstractFactory {

    private static void generateLevel(RoomFactory factory) {
        NormalRoom normalRoom = factory.createNormalRoom();
        System.out.println(normalRoom.generateLoot() + " " + normalRoom.generateBoss());

        HardRoom hardRoom = factory.createHardRoom();
        System.out.println(hardRoom.generateLoot() + " " + hardRoom.generateBoss());
        System.out.println("Secret: " + hardRoom.generateSecret(normalRoom));
    }

    public static void main(String[] args) {
        // Код уровня не знает, какие именно комнаты создаются. Он знает только,
        // что все они из одного семейства, и перепутать их невозможно.
        generateLevel(new BasementFactory());
        System.out.println();
        generateLevel(new CavesFactory());
    }
}
