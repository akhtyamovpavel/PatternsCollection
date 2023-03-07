package ru.akhcheck.patterns.prototype;

public class Table {
    private String material;

    protected Table(Table other) {
        material = other.material;
    }

    public Table(String material) {
        this.material = material;
    }

    @Override
    public Table clone() {
//        super.clone();
        return new Table(this);
    }

    @Override
    public String toString() {
        return "Table{" +
                "material='" + material + '\'' +
                '}';
    }
}
