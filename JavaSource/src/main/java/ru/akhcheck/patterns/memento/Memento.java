package ru.akhcheck.patterns.memento;

/**
 * Хранитель: снимок плюс имя, под которым он сохранён.
 *
 * <p>Смотритель хранит его целиком и внутрь не заглядывает. Это и есть граница:
 * состояние принадлежит хозяину, а не тому, кто складывает сохранения.
 */
public final class Memento {
    private final String name;
    private final State state;

    public Memento(String name, State state) {
        this.name = name;
        this.state = state;
    }

    public String getName() {
        return name;
    }

    public State getState() {
        return state;
    }
}
