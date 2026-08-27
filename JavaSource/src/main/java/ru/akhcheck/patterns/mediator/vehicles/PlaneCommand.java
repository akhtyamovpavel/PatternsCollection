package ru.akhcheck.patterns.mediator.vehicles;

/** Состояния самолёта в разговоре с диспетчером. */
public enum PlaneCommand {
    CONNECTED,
    WAITING,
    LANDING,
    LANDED
}
