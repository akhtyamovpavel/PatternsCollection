package ru.akhcheck.patterns.bridge.wheels;

import ru.akhcheck.patterns.bridge.chassis.Chassis;

public class PlaneWheel extends Wheel {
    public PlaneWheel(Chassis chassis) {
        super(chassis);
    }

    @Override
    public void pushWheel() {
        chassis.brake(0.1f);
        chassis.moveDown(0.1f);
    }

    @Override
    public void pullWheel() {
        chassis.accelerate(0.1f);
        chassis.moveUp(0.1f);
    }

    @Override
    public void pressGasPedal() {
        chassis.accelerate(0.1f);
    }

    @Override
    public void pressBreakPedal() {
        chassis.brake(0.1f);
        chassis.moveDown(0.1f);
    }

    @Override
    public void pressLeftButton() {
        chassis.beep();
    }

    @Override
    public void pressRightButton() {
        chassis.printInfo();
    }

    @Override
    public void moveRightWheel(float angle) {
        chassis.moveRight(angle);
    }

    @Override
    public void moveLeftWheel(float angle) {
        chassis.moveLeft(angle);
    }

    @Override
    public void pressUpButton() {

    }

    @Override
    public void pressDownButton() {

    }

    @Override
    public void printInfo() {
        chassis.printInfo();
    }
}
