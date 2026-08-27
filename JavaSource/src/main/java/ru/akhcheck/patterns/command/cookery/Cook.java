package ru.akhcheck.patterns.command.cookery;

import java.util.List;
import java.util.Map;

/** Исполнитель. Про команды не знает ничего и умеет только готовить. */
public class Cook {
    private static final Map<String, List<String>> RECIPES = Map.of(
            "Borsh", List.of("Boil water", "Crop vegetables", "Mix"),
            "Solyanka", List.of("Boil water", "Add meat", "Add mix of meat")
    );

    public void prepare(String dish) {
        List<String> steps = RECIPES.get(dish);
        if (steps == null) {
            System.out.println("Cook does not know how to make " + dish);
            return;
        }

        for (String step : steps) {
            System.out.println("  " + step);
        }
        System.out.println("  " + dish + " is ready");
    }
}
