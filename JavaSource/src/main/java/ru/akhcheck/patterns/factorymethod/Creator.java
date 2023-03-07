package ru.akhcheck.patterns.factorymethod;

public class Creator {
    public Vehicle create(String type) {
        if (type.equals("train")) {
            return new Train();
        } else {
            return new Auto();
        }
    }
}
