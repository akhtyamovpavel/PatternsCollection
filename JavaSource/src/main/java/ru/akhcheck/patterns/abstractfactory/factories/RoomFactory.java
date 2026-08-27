package ru.akhcheck.patterns.abstractfactory.factories;

import ru.akhcheck.patterns.abstractfactory.rooms.HardRoom;
import ru.akhcheck.patterns.abstractfactory.rooms.NormalRoom;

/**
 * Абстрактная фабрика: создаёт семейство комнат одного уровня.
 *
 * <p>Отличие от фабричного метода в слове «семейство». Фабричный метод создаёт
 * один объект, абстрактная фабрика гарантирует, что созданные объекты подходят
 * друг другу: комнаты подвала не перемешаются с комнатами пещер.
 */
public interface RoomFactory {
    NormalRoom createNormalRoom();

    HardRoom createHardRoom();
}
