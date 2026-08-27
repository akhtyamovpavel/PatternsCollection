package ru.akhcheck.patterns.visitor.rooms;

import ru.akhcheck.patterns.visitor.workers.Visitor;

/** Санузел: единственная комната, где плитка идёт и на потолок. */
public class BathRoom extends ElementRoom {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    @Override
    public String getName() {
        return "BathRoom";
    }
}
