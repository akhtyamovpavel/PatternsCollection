package ru.akhcheck.patterns.abstractfactory.rooms;

/** Обычная комната пещер. */
public class CavesNormalRoom implements NormalRoom {
    @Override
    public String generateLoot() {
        return "Caves loot";
    }

    @Override
    public String generateBoss() {
        return "Chub";
    }
}
