package ru.akhcheck.patterns.observer;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * Очередь сообщений, которая уведомляет подписчиков о каждом новом.
 *
 * <p>Очередь взята потокобезопасная: в примере сообщения кладут два потока
 * сразу, и обычный список пришлось бы закрывать замком руками.
 */
public class MessageStorage extends Subject {
    private final ConcurrentLinkedQueue<String> messages = new ConcurrentLinkedQueue<>();

    public void pushMessage(String message) {
        messages.add(message);
        notifyObservers(message);
    }

    public List<String> readMessages() {
        List<String> result = new ArrayList<>();
        String message = messages.poll();
        while (message != null) {
            result.add(message);
            message = messages.poll();
        }
        return result;
    }
}
