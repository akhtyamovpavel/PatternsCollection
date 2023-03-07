package ru.akhcheck.patterns.builder.builders;

import ru.akhcheck.patterns.builder.base.Burger;

public interface BurgerBuilder {
    public BurgerBuilder reset();

    public BurgerBuilder addLowBread();
    public BurgerBuilder addMeat();
    public BurgerBuilder addHighBread();
    public BurgerBuilder addVegetable();

    public Burger getBurger();

}
