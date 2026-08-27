package ru.akhcheck.patterns.state.states;

import ru.akhcheck.patterns.state.Direction;
import ru.akhcheck.patterns.state.TrafficLight;

/** Зелёный свет: следующим всегда идёт жёлтый в сторону красного. */
public class Green implements State {
    @Override
    public void switchState(TrafficLight light) {
        light.setState(new Yellow());
        light.setDirection(Direction.TO_RED);
    }

    @Override
    public String getStringState() {
        return "Green";
    }
}
