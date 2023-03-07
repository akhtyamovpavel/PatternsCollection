package ru.akhcheck.patterns.factorymethod;

public class AutoCreator extends AbstractCreator {
    @Override
    Vehicle create() {
        return new Auto();
    }
}
