package ru.akhcheck.patterns.prototype;

public class BarTable extends Table {

    private String drink;

    public BarTable(
        String material,
        String drink
    ) {
        super(material);
        this.drink = drink;
    }

    protected BarTable(BarTable other) {
        super(other);
        drink = other.drink;
    }

    @Override
    public BarTable clone() {
        return new BarTable(this);
    }

    @Override
    public String toString() {
        return "BarTable{" +
                "drink='" + drink + '\'' +
                '}' + super.toString();
    }
}
