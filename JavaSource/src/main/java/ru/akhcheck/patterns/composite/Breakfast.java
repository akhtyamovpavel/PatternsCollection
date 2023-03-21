package ru.akhcheck.patterns.composite;

public class Breakfast extends Dish {
    @Override
    public int GetCalories() {
        return super.GetCalories() - 10;
    }
}
