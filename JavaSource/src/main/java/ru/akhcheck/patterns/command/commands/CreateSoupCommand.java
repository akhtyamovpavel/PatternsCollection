package ru.akhcheck.patterns.command.commands;

import java.util.Map;
import ru.akhcheck.patterns.command.cookery.Cook;

/** Знает исполнителя и то, что ему сказать. Больше ничего. */
public class CreateSoupCommand implements Command {
    private static final Map<String, Integer> PRICES = Map.of("Borsh", 350, "Solyanka", 420);

    private final Cook cook;
    private final String dish;

    public CreateSoupCommand(Cook cook, String dish) {
        this.cook = cook;
        this.dish = dish;
    }

    @Override
    public void execute() {
        cook.prepare(dish);
    }

    @Override
    public int getPrice() {
        return PRICES.getOrDefault(dish, 0);
    }

    @Override
    public String toString() {
        return "soup: " + dish;
    }
}
