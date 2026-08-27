package ru.akhcheck.patterns.visitor.rooms;

import ru.akhcheck.patterns.visitor.workers.Visitor;

/**
 * Комната, к которой может прийти рабочий.
 *
 * <p>Метод accept всегда написан одинаково: комната зовёт у гостя тот метод,
 * который соответствует её типу. Такой приём называют двойной диспетчеризацией,
 * потому что выбор кода зависит и от типа комнаты, и от типа рабочего.
 */
public abstract class ElementRoom {
    private final Surface wall = new Surface();
    private final Surface floor = new Surface();
    private final Surface ceiling = new Surface();

    public abstract void accept(Visitor visitor);

    public abstract String getName();

    public Surface getWall() {
        return wall;
    }

    public Surface getFloor() {
        return floor;
    }

    public Surface getCeiling() {
        return ceiling;
    }

    public void showDecorations() {
        System.out.println(getName() + ":");
        System.out.println("  wall:    " + wall);
        System.out.println("  floor:   " + floor);
        System.out.println("  ceiling: " + ceiling);
    }
}
