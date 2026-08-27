package ru.akhcheck.patterns.state;

import ru.akhcheck.patterns.state.states.Red;
import ru.akhcheck.patterns.state.states.State;

/**
 * Хозяин состояния. Про цвета не знает ничего.
 *
 * <p>Обрати внимание, чего здесь нет: ни одного условия вида «если сейчас
 * красный, то дальше жёлтый». Такие условия живут в самих состояниях, и
 * добавление нового цвета не трогает этот класс.
 */
public class TrafficLight {
    private State state = new Red();
    private Direction direction = Direction.TO_GREEN;

    public void setState(State state) {
        this.state = state;
    }

    public Direction getDirection() {
        return direction;
    }

    public void setDirection(Direction direction) {
        this.direction = direction;
    }

    public void changeColor() {
        state.switchState(this);
    }

    public void printState() {
        System.out.println(state.getStringState());
    }
}
