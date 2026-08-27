package ru.akhcheck.patterns.state.states;

import ru.akhcheck.patterns.state.TrafficLight;

/**
 * Одно состояние светофора.
 *
 * <p>Смысл паттерна в том, что переход знает само состояние, а не хозяин.
 * У светофора нет ни одного условия про цвета: он просит текущее состояние
 * переключиться, а куда именно, решает состояние.
 */
public interface State {
    void switchState(TrafficLight light);

    String getStringState();
}
