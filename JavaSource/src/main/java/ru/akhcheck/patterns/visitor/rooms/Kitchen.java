package ru.akhcheck.patterns.visitor.rooms;

import ru.akhcheck.patterns.visitor.workers.Visitor;

/** Кухня: сюда приходят все рабочие, кроме оконщика в санузел. */
public class Kitchen extends ElementRoom {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    @Override
    public String getName() {
        return "Kitchen";
    }
}
