package ru.akhcheck.patterns.observer;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Ничего не печатает, только считает.
 *
 * <p>Показывает, что подписчики независимы: источник один, а делают они разное
 * и друг про друга не знают. Счётчик атомарный, потому что сообщения приходят
 * из нескольких потоков.
 */
public class CountingObserver implements Observer {
    private final AtomicInteger count = new AtomicInteger();

    @Override
    public void update(String message) {
        count.incrementAndGet();
    }

    public int getCount() {
        return count.get();
    }
}
