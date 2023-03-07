package ru.akhcheck.patterns.factorymethod;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class MainFactoryMethod {
    public static void main(String[] args) {
        Creator creator = new Creator();

        Vehicle auto = creator.create("auto");

        Vehicle train = creator.create("train");
        auto.move();
        train.move();

        List<AbstractCreator> creators = Arrays.asList(
             new AutoCreator(),
             new TrainCreator()
        );

        List<Vehicle> vehicles = creators.stream().map(
            AbstractCreator::create
        ).collect(Collectors.toList());

        for (Vehicle vehicle: vehicles) {
            vehicle.move();
        }
    }
}
