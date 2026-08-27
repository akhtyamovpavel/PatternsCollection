package ru.akhcheck.patterns.visitor.workers;

import ru.akhcheck.patterns.visitor.rooms.BathRoom;
import ru.akhcheck.patterns.visitor.rooms.Home;
import ru.akhcheck.patterns.visitor.rooms.Kitchen;
import ru.akhcheck.patterns.visitor.rooms.LivingRoom;

/** Маляр: красит стены и потолки, пол не трогает. */
public class Painter implements Visitor {
    @Override
    public void visit(Kitchen kitchen) {
        kitchen.getCeiling().setColor("white");
    }

    @Override
    public void visit(LivingRoom livingRoom) {
        livingRoom.getWall().setColor("beige");
        livingRoom.getCeiling().setColor("white");
    }

    @Override
    public void visit(BathRoom bathRoom) {
        bathRoom.getCeiling().setColor("white");
    }

    @Override
    public void visit(Home home) {
        System.out.println("Painter came to the house");
    }
}
