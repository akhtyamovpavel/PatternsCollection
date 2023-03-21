package ru.akhcheck.patterns.builder;

import ru.akhcheck.patterns.builder.base.Burger;
import ru.akhcheck.patterns.builder.builders.VegiburgerBuilder;
import ru.akhcheck.patterns.builder.builders.BurgerBuilder;
import ru.akhcheck.patterns.builder.builders.HamburgerBuilder;
import ru.akhcheck.patterns.builder.builders.VegiburgerBuilder;

public class MainBuilder {
    public static void main(String[] args) {
        Chef chef = new Chef();
        BurgerBuilder builder = new HamburgerBuilder();
        chef.setBuilder(builder);

        Burger burger = chef.Cook();

        System.out.println(burger);

        BurgerBuilder vegiBuilder = new VegiburgerBuilder();
        chef.setBuilder(vegiBuilder);

        Burger vegiburger = chef.Cook();
        System.out.println(vegiburger);
    }
}
