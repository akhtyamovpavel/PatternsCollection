package ru.akhcheck.patterns.observer;

import java.util.ArrayList;
import java.util.List;

/**
 * Источник событий. Держит подписчиков и рассылает уведомления.
 *
 * <p>Отписка нужна не для красоты: без неё источник держит ссылку на
 * подписчика навсегда, и тот не будет собран сборщиком мусора.
 */
public class Subject {
    private final List<Observer> observers = new ArrayList<>();

    public void attach(Observer observer) {
        if (!observers.contains(observer)) {
            observers.add(observer);
        }
    }

    public void detach(Observer observer) {
        observers.remove(observer);
    }

    protected void notifyObservers(String message) {
        // Идём по копии: подписчик вправе отписаться прямо внутри update.
        for (Observer observer : new ArrayList<>(observers)) {
            observer.update(message);
        }
    }
}
