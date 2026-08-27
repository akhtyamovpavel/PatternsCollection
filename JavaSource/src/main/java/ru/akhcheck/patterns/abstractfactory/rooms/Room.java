package ru.akhcheck.patterns.abstractfactory.rooms;

/** Общая часть любой комнаты: она умеет отдать добычу и босса. */
public interface Room {
    String generateLoot();

    String generateBoss();
}
