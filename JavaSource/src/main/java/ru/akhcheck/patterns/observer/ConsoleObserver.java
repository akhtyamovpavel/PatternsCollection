package ru.akhcheck.patterns.observer;

/** Печатает каждое сообщение. */
public class ConsoleObserver implements Observer {
    private final String name;

    public ConsoleObserver(String name) {
        this.name = name;
    }

    @Override
    public void update(String message) {
        System.out.println(name + " received: " + message);
    }
}
