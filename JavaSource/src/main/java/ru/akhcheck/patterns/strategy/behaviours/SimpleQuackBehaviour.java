package ru.akhcheck.patterns.strategy.behaviours;

/** Обычное кряканье. */
public class SimpleQuackBehaviour implements QuackBehaviour {
    @Override
    public void execute() {
        System.out.println("Quack");
    }
}
