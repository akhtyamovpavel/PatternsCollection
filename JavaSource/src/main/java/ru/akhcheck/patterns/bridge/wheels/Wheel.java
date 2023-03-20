package ru.akhcheck.patterns.bridge.wheels;

import ru.akhcheck.patterns.bridge.chassis.Chassis;

public abstract class Wheel {
    public abstract void pushWheel();
    public abstract void pullWheel();
    public abstract void pressGasPedal();
    public abstract void pressBreakPedal();
    public abstract void pressLeftButton();
    public abstract void pressRightButton();
    public abstract void moveRightWheel(float angle);
    public abstract void moveLeftWheel(float angle);
    public abstract void pressUpButton();
    public abstract void pressDownButton();
    public abstract void printInfo();

    public Wheel(Chassis chassis) {
        this.chassis = chassis;
    }
    protected Chassis chassis;
}
