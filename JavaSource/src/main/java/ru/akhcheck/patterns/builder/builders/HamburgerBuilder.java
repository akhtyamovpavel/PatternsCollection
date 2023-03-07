package ru.akhcheck.patterns.builder.builders;

import ru.akhcheck.patterns.builder.base.Burger;

import java.util.LinkedList;
import java.util.List;

public class HamburgerBuilder implements BurgerBuilder {
    private List<String> components = new LinkedList<>();

    @Override
    public BurgerBuilder reset() {
        components.clear();
        return this;
    }

    @Override
    public BurgerBuilder addLowBread() {
        components.add("WhiteLoaf");
        return this;
    }

    @Override
    public BurgerBuilder addMeat() {
        components.add("Farsh");
        return this;
    }

    @Override
    public BurgerBuilder addHighBread() {
        components.add("GrayLoaf");
        return this;
    }

    @Override
    public BurgerBuilder addVegetable() {
        components.add("Tomato");
        return this;
    }

    @Override
    public Burger getBurger() {
        return new Burger(components);
    }
}
