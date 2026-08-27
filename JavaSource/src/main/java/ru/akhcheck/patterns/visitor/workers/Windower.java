package ru.akhcheck.patterns.visitor.workers;

import ru.akhcheck.patterns.visitor.rooms.BathRoom;
import ru.akhcheck.patterns.visitor.rooms.Home;
import ru.akhcheck.patterns.visitor.rooms.Kitchen;
import ru.akhcheck.patterns.visitor.rooms.LivingRoom;

/** Оконщик: ставит окна там, где они бывают. */
public class Windower implements Visitor {
    @Override
    public void visit(Kitchen kitchen) {
        kitchen.getWall().setMaterial("brick with window");
    }

    @Override
    public void visit(LivingRoom livingRoom) {
        livingRoom.getWall().setMaterial("brick with panoramic window");
    }

    @Override
    public void visit(BathRoom bathRoom) {
        // В санузле окна не ставим.
    }

    @Override
    public void visit(Home home) {
        System.out.println("Windower came to the house");
    }
}
