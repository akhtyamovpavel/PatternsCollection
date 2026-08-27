package ru.akhcheck.patterns.facade.facades;

import java.util.Map;
import ru.akhcheck.patterns.abstractfactory.factories.BasementFactory;
import ru.akhcheck.patterns.abstractfactory.factories.CavesFactory;
import ru.akhcheck.patterns.abstractfactory.factories.RoomFactory;
import ru.akhcheck.patterns.abstractfactory.rooms.Room;

/**
 * Прячет выбор фабрики и сборку комнаты за одним методом.
 *
 * <p>Вызывающему не нужно знать, что за уровнем стоит своя фабрика и что
 * комната отдаёт добычу и босса по отдельности.
 */
public class IsaacFacade {
    private final Map<String, RoomFactory> factories = Map.of(
            "basement", new BasementFactory(),
            "caves", new CavesFactory()
    );

    public String createGame(String difficulty) {
        return createGame(difficulty, "basement");
    }

    public String createGame(String difficulty, String level) {
        RoomFactory factory = factories.get(level);
        if (factory == null) {
            throw new IllegalArgumentException("unknown level: " + level);
        }

        Room room;
        if ("hard".equals(difficulty)) {
            room = factory.createHardRoom();
        } else {
            room = factory.createNormalRoom();
        }

        return room.generateLoot() + " " + room.generateBoss();
    }
}
