package ru.akhcheck.patterns.abstractfactory.rooms;

/** Сложная комната. Умеет ещё и прятать секрет, которого нет у обычной. */
public interface HardRoom extends Room {
    String generateSecret(Room neighbour);
}
