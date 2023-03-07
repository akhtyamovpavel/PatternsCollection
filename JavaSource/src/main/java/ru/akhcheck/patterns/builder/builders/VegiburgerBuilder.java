package ru.akhcheck.patterns.builder.builders;

import ru.akhcheck.patterns.builder.base.Burger;

import java.util.LinkedList;
import java.util.List;

public class VegiburgerBuilder implements BurgerBuilder {
    private List<String> components = new LinkedList<>();

    @Override
    public BurgerBuilder reset() {
        components.clear();
        return this;
    }

    @Override
    public BurgerBuilder addLowBread() {
        components.add("GrayLoaf");
        return this;
    }

    @Override
    public BurgerBuilder addMeat() {
        return this;
    }

    @Override
    public BurgerBuilder addHighBread() {
        components.add("BlackLoaf");
        return this;
    }

    @Override
    public BurgerBuilder addVegetable() {
        components.add("Salade");
        return this;
    }

    @Override
    public Burger getBurger() {
        return new Burger(components);
    }
}
