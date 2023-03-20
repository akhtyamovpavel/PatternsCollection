package ru.akhcheck.patterns.composite;

import java.util.ArrayList;

public class Dish implements DishComponent{
    private ArrayList<DishComponent> components = new ArrayList<>();

    public int GetCalories() {
        int calories = 0;
        for (DishComponent component: components) {
            calories += component.GetCalories();
        }
        return calories;
    }

    public Dish add(DishComponent component) {
        components.add(component);
        return this;
    }

}
