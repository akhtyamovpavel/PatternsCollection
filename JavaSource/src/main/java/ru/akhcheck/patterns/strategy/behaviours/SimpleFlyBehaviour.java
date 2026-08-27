package ru.akhcheck.patterns.strategy.behaviours;

/** Обычный полёт. */
public class SimpleFlyBehaviour implements FlyBehaviour {
    @Override
    public void execute() {
        System.out.println("Duck is flying");
    }
}
