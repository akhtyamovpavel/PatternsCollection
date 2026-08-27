package ru.akhcheck.patterns.abstractfactory.factories;

import ru.akhcheck.patterns.abstractfactory.rooms.CavesHardRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.CavesNormalRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.HardRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.NormalRoom;

/** Фабрика комнат пещер. */
public class CavesFactory implements RoomFactory {
    @Override
    public NormalRoom createNormalRoom() {
        return new CavesNormalRoom();
    }

    @Override
    public HardRoom createHardRoom() {
        return new CavesHardRoom();
    }
}
