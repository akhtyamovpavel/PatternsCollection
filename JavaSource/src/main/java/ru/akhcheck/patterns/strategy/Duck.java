package ru.akhcheck.patterns.strategy;

import ru.akhcheck.patterns.strategy.behaviours.FlyBehaviour;
import ru.akhcheck.patterns.strategy.behaviours.QuackBehaviour;
import ru.akhcheck.patterns.strategy.behaviours.SwimBehaviour;

/**
 * Утка держит поведения, а не наследует их.
 *
 * <p>Если бы поведения были в наследниках, каждое новое сочетание требовало бы
 * отдельного класса: два способа летать на два способа крякать дают четыре
 * класса, три на три уже девять. Здесь сочетания собираются на месте.
 */
public class Duck {
    private FlyBehaviour flyBehaviour;
    private QuackBehaviour quackBehaviour;
    private SwimBehaviour swimBehaviour;

    public void setFlyBehaviour(FlyBehaviour behaviour) {
        this.flyBehaviour = behaviour;
    }

    public void setQuackBehaviour(QuackBehaviour behaviour) {
        this.quackBehaviour = behaviour;
    }

    public void setSwimBehaviour(SwimBehaviour behaviour) {
        this.swimBehaviour = behaviour;
    }

    public void fly() {
        requireBehaviour(flyBehaviour, "fly");
        flyBehaviour.execute();
    }

    public void quack() {
        requireBehaviour(quackBehaviour, "quack");
        quackBehaviour.execute();
    }

    public void swim() {
        requireBehaviour(swimBehaviour, "swim");
        swimBehaviour.execute();
    }

    private void requireBehaviour(Object behaviour, String name) {
        if (behaviour == null) {
            throw new IllegalStateException(name + " behaviour is not set");
        }
    }
}
