package ru.akhcheck.patterns.prototype;

import ru.akhcheck.patterns.factorymethod.AbstractCreator;
import ru.akhcheck.patterns.factorymethod.AutoCreator;
import ru.akhcheck.patterns.factorymethod.TrainCreator;
import ru.akhcheck.patterns.factorymethod.Vehicle;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class MainPrototype {
    public static void main(String[] args) {

        Table table = new Table("wood");
        BarTable barTable = new BarTable(
                "wood", "water"
        );

        List<Table> tables = Arrays.asList(
            table, barTable
        );

        ArrayList<Table> clones = (ArrayList<Table>) tables.stream().map(
                Table::clone
        ).collect(Collectors.toList());

        System.out.println(clones.get(0));
        System.out.println(clones.get(1));
    }
}
