package ru.akhcheck.patterns.memento;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * Смотритель: хранит сохранения и не знает, что внутри них.
 *
 * <p>Он умеет только две вещи: попросить хозяина сделать снимок и отдать снимок
 * обратно. Ни одного обращения к полям состояния здесь нет и быть не должно.
 */
public class Caretaker {
    private final Originator originator;
    private final Map<String, Memento> mementos = new HashMap<>();

    public Caretaker(Originator originator) {
        this.originator = originator;
    }

    public void save(String saveName) {
        mementos.put(saveName, originator.save(saveName));
    }

    public void load(String saveName) {
        Memento memento = mementos.get(saveName);
        if (memento == null) {
            throw new IllegalArgumentException("save not found: " + saveName);
        }
        originator.restore(memento);
    }

    public Set<String> getSaves() {
        return mementos.keySet();
    }
}
