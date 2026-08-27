package ru.akhcheck.patterns.command.cookery;

import java.util.List;
import java.util.Map;

/** Второй исполнитель. Тоже ничего не знает про команды. */
public class Bartender {
    private static final Map<String, List<String>> RECIPES = Map.of(
            "Mojito", List.of("Crush mint", "Add lime", "Add rum", "Add soda"),
            "Americano", List.of("Pour espresso", "Add water")
    );

    public void mix(String drink) {
        List<String> steps = RECIPES.get(drink);
        if (steps == null) {
            System.out.println("Bartender does not know how to make " + drink);
            return;
        }

        for (String step : steps) {
            System.out.println("  " + step);
        }
        System.out.println("  " + drink + " is ready");
    }
}
