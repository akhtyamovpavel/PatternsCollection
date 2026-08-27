package ru.akhcheck.patterns.visitor.rooms;

import ru.akhcheck.patterns.visitor.workers.Visitor;

/** Гостиная: здесь не бывает плитки и воды. */
public class LivingRoom extends ElementRoom {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    @Override
    public String getName() {
        return "LivingRoom";
    }
}
