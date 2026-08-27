package ru.akhcheck.patterns.visitor.rooms;

import java.util.ArrayList;
import java.util.List;
import ru.akhcheck.patterns.visitor.workers.Visitor;

/**
 * Дом это тоже комната, только он состоит из других комнат.
 *
 * <p>Здесь видно, как посетитель и компоновщик работают вместе: дом пускает
 * гостя к себе, а потом проводит его по всем комнатам.
 */
public class Home extends ElementRoom {
    private final List<ElementRoom> rooms = new ArrayList<>();

    public Home add(ElementRoom room) {
        rooms.add(room);
        return this;
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
        for (ElementRoom room : rooms) {
            room.accept(visitor);
        }
    }

    @Override
    public String getName() {
        return "Home";
    }
}
