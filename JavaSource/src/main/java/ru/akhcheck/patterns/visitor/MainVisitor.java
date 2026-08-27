package ru.akhcheck.patterns.visitor;

import java.util.List;
import ru.akhcheck.patterns.visitor.rooms.BathRoom;
import ru.akhcheck.patterns.visitor.rooms.ElementRoom;
import ru.akhcheck.patterns.visitor.rooms.Home;
import ru.akhcheck.patterns.visitor.rooms.Kitchen;
import ru.akhcheck.patterns.visitor.rooms.LivingRoom;
import ru.akhcheck.patterns.visitor.workers.Painter;
import ru.akhcheck.patterns.visitor.workers.SanTech;
import ru.akhcheck.patterns.visitor.workers.Tiler;
import ru.akhcheck.patterns.visitor.workers.Visitor;
import ru.akhcheck.patterns.visitor.workers.Windower;

/** Точка входа примера посетителя. */
public class MainVisitor {

    public static void main(String[] args) {
        List<ElementRoom> rooms = List.of(new Kitchen(), new LivingRoom(), new BathRoom());

        Home home = new Home();
        for (ElementRoom room : rooms) {
            home.add(room);
        }

        // Каждый рабочий обходит весь дом целиком: accept сам зовёт visit(Home),
        // а потом проводит гостя по комнатам. Ни одна комната не знает, какие
        // рабочие вообще существуют.
        List<Visitor> workers = List.of(new Tiler(), new Painter(), new Windower(), new SanTech());
        for (Visitor worker : workers) {
            home.accept(worker);
            System.out.println();
        }

        System.out.println("что получилось:");
        for (ElementRoom room : rooms) {
            room.showDecorations();
        }
    }
}
