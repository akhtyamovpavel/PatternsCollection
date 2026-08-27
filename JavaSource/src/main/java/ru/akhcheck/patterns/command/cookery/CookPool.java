package ru.akhcheck.patterns.command.cookery;

/** Отдаёт исполнителей. В настоящей системе на его месте был бы пул. */
public final class CookPool {
    private static final Cook COOK = new Cook();
    private static final Bartender BARTENDER = new Bartender();

    private CookPool() {
    }

    public static Cook getCook() {
        return COOK;
    }

    public static Bartender getBartender() {
        return BARTENDER;
    }
}
