package ru.akhcheck.patterns.state;

/** Точка входа примера состояния. */
public class MainState {

    public static void main(String[] args) {
        TrafficLight light = new TrafficLight();

        for (int stateSwitch = 0; stateSwitch < 10; ++stateSwitch) {
            light.printState();
            light.changeColor();
        }
    }
}
