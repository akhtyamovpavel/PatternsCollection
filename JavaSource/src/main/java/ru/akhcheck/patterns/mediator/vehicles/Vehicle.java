package ru.akhcheck.patterns.mediator.vehicles;

import ru.akhcheck.patterns.mediator.dispatcher.Dispatcher;

/**
 * Участник, который общается только через посредника.
 *
 * <p>Ключевое здесь то, чего нет: у самолёта нет ссылок на другие самолёты. Он
 * знает лишь диспетчера, поэтому добавление десятого самолёта не меняет ни
 * одного из девяти существующих.
 */
public abstract class Vehicle {
    private final String name;
    private Dispatcher dispatcher;

    protected Vehicle(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setDispatcher(Dispatcher dispatcher) {
        this.dispatcher = dispatcher;
    }

    protected boolean notifyDispatcher(String message) {
        if (dispatcher == null) {
            throw new IllegalStateException(name + " has no dispatcher");
        }
        return dispatcher.notify(this, message);
    }
}
