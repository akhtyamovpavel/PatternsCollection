package ru.akhcheck.patterns.mediator.dispatcher;

import ru.akhcheck.patterns.mediator.vehicles.Vehicle;

/** Посредник: единственный, кто знает про всех участников сразу. */
public interface Dispatcher {
    boolean notify(Vehicle vehicle, String message);
}
