package ru.akhcheck.patterns.visitor.workers;

import ru.akhcheck.patterns.visitor.rooms.BathRoom;
import ru.akhcheck.patterns.visitor.rooms.Home;
import ru.akhcheck.patterns.visitor.rooms.Kitchen;
import ru.akhcheck.patterns.visitor.rooms.LivingRoom;

/**
 * Рабочий, который приходит в дом.
 *
 * <p>Паттерн нужен тогда, когда новых операций больше, чем новых типов.
 * Добавить маляра значит написать один класс и не трогать ни одной комнаты.
 * Обратная сторона честная: добавить новую комнату значит дописать метод во все
 * классы рабочих сразу.
 */
public interface Visitor {
    void visit(Kitchen kitchen);

    void visit(LivingRoom livingRoom);

    void visit(BathRoom bathRoom);

    void visit(Home home);
}
