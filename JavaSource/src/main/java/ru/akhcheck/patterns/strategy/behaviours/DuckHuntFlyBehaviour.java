package ru.akhcheck.patterns.strategy.behaviours;

/** Утка из игры летает иначе, и сама утка про это отличие не знает. */
public class DuckHuntFlyBehaviour implements FlyBehaviour {
    @Override
    public void execute() {
        System.out.println("Duck is flying away from the hunter");
    }
}
