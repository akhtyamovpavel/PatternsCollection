package ru.akhcheck.patterns.visitor.rooms;

/** Поверхность комнаты: из чего сделана и какого цвета. */
public class Surface {
    private String material = "unknown";
    private String color = "unknown";

    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return material + ", " + color;
    }
}
