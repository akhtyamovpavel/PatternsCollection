package ru.akhcheck.patterns.composite;

public class MainComposite {


    public static void main(String[] args) {
        Dish ration = new Dish().add(
                new Breakfast().add(
                        new Milk()
                ).add(
                        new Milk()
                )
        ).add(new Milk());
        System.out.println(ration.GetCalories());
    }
}
