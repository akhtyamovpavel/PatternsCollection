package ru.akhcheck.patterns.factorymethod;

public class TrainCreator extends AbstractCreator {
    @Override
    Vehicle create() {
        return new Train();
    }
}
