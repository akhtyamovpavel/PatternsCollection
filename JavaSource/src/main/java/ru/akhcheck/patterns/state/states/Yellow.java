package ru.akhcheck.patterns.state.states;

import ru.akhcheck.patterns.state.Direction;
import ru.akhcheck.patterns.state.TrafficLight;

/**
 * Жёлтый единственный, кому нужно направление.
 *
 * <p>Из красного он ведёт в зелёный, из зелёного в красный, и без хранимого
 * направления отличить эти два случая нельзя.
 */
public class Yellow implements State {
    @Override
    public void switchState(TrafficLight light) {
        if (light.getDirection() == Direction.TO_GREEN) {
            light.setState(new Green());
            return;
        }
        light.setState(new Red());
    }

    @Override
    public String getStringState() {
        return "Yellow";
    }
}
