package ru.akhcheck.patterns.abstractfactory.rooms;

/** Сложная комната пещер: у неё есть секрет. */
public class CavesHardRoom implements HardRoom {
    @Override
    public String generateLoot() {
        return "Caves loot x2";
    }

    @Override
    public String generateBoss() {
        return "Chub 300hp";
    }

    @Override
    public String generateSecret(Room neighbour) {
        return "flooded passage after " + neighbour.generateBoss();
    }
}
