package ru.akhcheck.patterns.memento;

import java.util.Collections;
import java.util.List;

/**
 * Снимок состояния игры. Неизменяемый намеренно.
 *
 * <p>Если снимок можно было бы поправить снаружи, он перестал бы быть снимком:
 * сохранение перезаписывалось бы задним числом. Поэтому поля финальные, а
 * список отдаётся только для чтения.
 */
public final class State {
    private final int level;
    private final int experience;
    private final List<String> inventory;

    public State(int level, int experience, List<String> inventory) {
        this.level = level;
        this.experience = experience;
        this.inventory = Collections.unmodifiableList(List.copyOf(inventory));
    }

    public static State empty() {
        return new State(0, 0, List.of());
    }

    public int getLevel() {
        return level;
    }

    public int getExperience() {
        return experience;
    }

    public List<String> getInventory() {
        return inventory;
    }
}
