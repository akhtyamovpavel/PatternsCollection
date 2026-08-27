package ru.akhcheck.patterns.strategy.behaviours;

/** Обычное плавание. */
public class SimpleSwimBehaviour implements SwimBehaviour {
    @Override
    public void execute() {
        System.out.println("Duck is swimming");
    }
}
