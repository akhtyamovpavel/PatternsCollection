package ru.akhcheck.patterns.abstractfactory.factories;

import ru.akhcheck.patterns.abstractfactory.rooms.BasementHardRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.BasementNormalRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.HardRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.NormalRoom;

/** Фабрика комнат подвала. */
public class BasementFactory implements RoomFactory {
    @Override
    public NormalRoom createNormalRoom() {
        return new BasementNormalRoom();
    }

    @Override
    public HardRoom createHardRoom() {
        return new BasementHardRoom();
    }
}
