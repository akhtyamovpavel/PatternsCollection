package ru.akhcheck.patterns.builder;

import ru.akhcheck.patterns.builder.base.Burger;
import ru.akhcheck.patterns.builder.builders.BurgerBuilder;

public class Chef {
    private BurgerBuilder builder;

    public Burger Cook() {
        return (
            builder
                .reset()
                .addLowBread()
                .addMeat()
                .addVegetable()
                .addHighBread()
                .getBurger()
        );
    }

    public void setBuilder(BurgerBuilder builder) {
        this.builder = builder;
    }
}
