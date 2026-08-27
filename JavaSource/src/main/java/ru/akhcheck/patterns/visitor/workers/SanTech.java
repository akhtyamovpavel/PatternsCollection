package ru.akhcheck.patterns.visitor.workers;

import ru.akhcheck.patterns.visitor.rooms.BathRoom;
import ru.akhcheck.patterns.visitor.rooms.Home;
import ru.akhcheck.patterns.visitor.rooms.Kitchen;
import ru.akhcheck.patterns.visitor.rooms.LivingRoom;

/** Сантехник: работает только там, где есть вода. */
public class SanTech implements Visitor {
    @Override
    public void visit(Kitchen kitchen) {
        System.out.println("  SanTech installs a sink in the kitchen");
    }

    @Override
    public void visit(LivingRoom livingRoom) {
        // В гостиной воды нет.
    }

    @Override
    public void visit(BathRoom bathRoom) {
        System.out.println("  SanTech installs a bath and a sink");
    }

    @Override
    public void visit(Home home) {
        System.out.println("SanTech came to the house");
    }
}
