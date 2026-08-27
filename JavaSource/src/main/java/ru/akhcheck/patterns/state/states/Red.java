package ru.akhcheck.patterns.state.states;

import ru.akhcheck.patterns.state.Direction;
import ru.akhcheck.patterns.state.TrafficLight;

/** Красный свет: следующим всегда идёт жёлтый в сторону зелёного. */
public class Red implements State {
    @Override
    public void switchState(TrafficLight light) {
        light.setState(new Yellow());
        light.setDirection(Direction.TO_GREEN);
    }

    @Override
    public String getStringState() {
        return "Red";
    }
}
