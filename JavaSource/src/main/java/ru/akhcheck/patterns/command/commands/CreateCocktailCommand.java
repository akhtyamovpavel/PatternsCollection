package ru.akhcheck.patterns.command.commands;

import java.util.Map;
import ru.akhcheck.patterns.command.cookery.Bartender;

/** Команда на приготовление коктейля. */
public class CreateCocktailCommand implements Command {
    private static final Map<String, Integer> PRICES = Map.of("Mojito", 480, "Americano", 200);

    private final Bartender bartender;
    private final String drink;

    public CreateCocktailCommand(Bartender bartender, String drink) {
        this.bartender = bartender;
        this.drink = drink;
    }

    @Override
    public void execute() {
        bartender.mix(drink);
    }

    @Override
    public int getPrice() {
        return PRICES.getOrDefault(drink, 0);
    }

    @Override
    public String toString() {
        return "cocktail: " + drink;
    }
}
