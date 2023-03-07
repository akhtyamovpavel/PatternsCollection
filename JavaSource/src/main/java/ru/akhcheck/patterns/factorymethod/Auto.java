package ru.akhcheck.patterns.factorymethod;

public class Auto implements Vehicle {
    @Override
    public void move() {
        System.out.println("Vrum");
    }
}
