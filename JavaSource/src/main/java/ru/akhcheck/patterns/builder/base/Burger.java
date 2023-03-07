package ru.akhcheck.patterns.builder.base;

import java.util.List;

public class Burger {
    private List<String> components;

    public Burger(List<String> components) {
        this.components = components;
    }

    @Override
    public String toString() {
        return "Burger{" +
                "components=" + components +
                '}';
    }
}
