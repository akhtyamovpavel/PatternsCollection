package ru.akhcheck.patterns.mediator;

import ru.akhcheck.patterns.mediator.dispatcher.PlaneDispatcher;
import ru.akhcheck.patterns.mediator.vehicles.Plane;

/** Точка входа примера посредника. */
public class MainMediator {

    public static void main(String[] args) {
        PlaneDispatcher dispatcher = new PlaneDispatcher();

        Plane first = new Plane("SU-100");
        Plane second = new Plane("SU-200");

        dispatcher.addPlane(first);
        dispatcher.addPlane(second);

        // Первый занимает полосу и освобождает её, второй садится следом.
        first.land();
        System.out.println();
        second.land();
        System.out.println();

        System.out.println("статусы: " + first.getStatus() + " " + second.getStatus());
    }
}
