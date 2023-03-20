package ru.akhcheck.patterns.composite;

public class Milk implements DishComponent {

    @Override
    public int GetCalories() {
        return 100;
    }
}
