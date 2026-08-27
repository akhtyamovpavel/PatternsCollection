package ru.akhcheck.patterns.visitor.workers;

import ru.akhcheck.patterns.visitor.rooms.BathRoom;
import ru.akhcheck.patterns.visitor.rooms.Home;
import ru.akhcheck.patterns.visitor.rooms.Kitchen;
import ru.akhcheck.patterns.visitor.rooms.LivingRoom;

/** Плиточник: кладёт плитку там, где она уместна. */
public class Tiler implements Visitor {
    @Override
    public void visit(Kitchen kitchen) {
        kitchen.getFloor().setMaterial("tile");
        kitchen.getWall().setMaterial("tile");
    }

    @Override
    public void visit(LivingRoom livingRoom) {
        // В гостиной плитка не нужна, и рабочий честно ничего не делает.
    }

    @Override
    public void visit(BathRoom bathRoom) {
        bathRoom.getFloor().setMaterial("tile");
        bathRoom.getWall().setMaterial("tile");
        bathRoom.getCeiling().setMaterial("tile");
    }

    @Override
    public void visit(Home home) {
        System.out.println("Tiler came to the house");
    }
}
