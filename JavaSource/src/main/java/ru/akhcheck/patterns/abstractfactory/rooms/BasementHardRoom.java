package ru.akhcheck.patterns.abstractfactory.rooms;

/** Сложная комната подвала: у неё есть секрет. */
public class BasementHardRoom implements HardRoom {
    @Override
    public String generateLoot() {
        return "Basement loot x2";
    }

    @Override
    public String generateBoss() {
        return "Monstro 200hp";
    }

    @Override
    public String generateSecret(Room neighbour) {
        return "secret behind " + neighbour.generateBoss();
    }
}
