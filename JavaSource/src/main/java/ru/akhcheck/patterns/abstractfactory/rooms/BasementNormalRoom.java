package ru.akhcheck.patterns.abstractfactory.rooms;

/** Обычная комната подвала. */
public class BasementNormalRoom implements NormalRoom {
    @Override
    public String generateLoot() {
        return "Basement loot";
    }

    @Override
    public String generateBoss() {
        return "Monstro";
    }
}
