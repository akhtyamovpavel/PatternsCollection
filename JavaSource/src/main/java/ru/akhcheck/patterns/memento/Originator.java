package ru.akhcheck.patterns.memento;

import java.util.ArrayList;
import java.util.List;

/**
 * Хозяин состояния: игра.
 *
 * <p>Только он умеет делать снимок и только он умеет из снимка восстановиться.
 * Смотритель снаружи не может ни прочитать поля, ни собрать снимок сам.
 */
public class Originator {
    private static final int LEVEL_EXPERIENCE = 100;

    private State state = State.empty();

    public void startNewGame() {
        state = new State(1, 0, List.of("knife"));
    }

    public void increaseLevel() {
        int nextLevel = state.getLevel() + 1;
        List<String> inventory = new ArrayList<>(state.getInventory());
        inventory.add("trophy-" + nextLevel);
        state = new State(nextLevel, state.getExperience() + LEVEL_EXPERIENCE, inventory);
    }

    public Memento save(String saveName) {
        return new Memento(saveName, state);
    }

    public void restore(Memento memento) {
        state = memento.getState();
    }

    public void showCurrentProgress() {
        System.out.println(
                "level=" + state.getLevel()
                        + " experience=" + state.getExperience()
                        + " inventory=" + state.getInventory()
        );
    }
}
