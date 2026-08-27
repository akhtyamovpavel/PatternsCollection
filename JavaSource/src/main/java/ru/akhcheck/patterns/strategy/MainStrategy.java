package ru.akhcheck.patterns.strategy;

import ru.akhcheck.patterns.strategy.behaviours.DuckHuntFlyBehaviour;
import ru.akhcheck.patterns.strategy.behaviours.SimpleFlyBehaviour;
import ru.akhcheck.patterns.strategy.behaviours.SimpleQuackBehaviour;
import ru.akhcheck.patterns.strategy.behaviours.SimpleSwimBehaviour;

/** Точка входа примера стратегии. */
public class MainStrategy {

    public static void main(String[] args) {
        Duck duck = new Duck();
        duck.setFlyBehaviour(new SimpleFlyBehaviour());
        duck.setQuackBehaviour(new SimpleQuackBehaviour());
        duck.setSwimBehaviour(new SimpleSwimBehaviour());
        duck.fly();
        duck.quack();
        duck.swim();

        System.out.println();

        // Тот же класс утки, другое поведение полёта. Ни одного наследника.
        Duck duckHunt = new Duck();
        duckHunt.setFlyBehaviour(new DuckHuntFlyBehaviour());
        duckHunt.setQuackBehaviour(new SimpleQuackBehaviour());
        duckHunt.fly();
        duckHunt.quack();

        System.out.println();

        // Поведение меняется и во время работы: утка устала убегать.
        duckHunt.setFlyBehaviour(new SimpleFlyBehaviour());
        duckHunt.fly();
    }
}
