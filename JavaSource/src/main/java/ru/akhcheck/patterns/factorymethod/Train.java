package ru.akhcheck.patterns.factorymethod;

public class Train implements Vehicle {
    @Override
    public void move() {
        System.out.println("Tu-tu");
    }
}
