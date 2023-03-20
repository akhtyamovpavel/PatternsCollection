package ru.akhcheck.patterns.bridge.wheels;

import ru.akhcheck.patterns.bridge.chassis.Chassis;

public class Gamepad extends Wheel {
    public Gamepad(Chassis chassis) {
        super(chassis);
    }

    @Override
    public void pushWheel() {
        chassis.beep();
    }

    @Override
    public void pullWheel() {

    }

    @Override
    public void pressGasPedal() {
        chassis.accelerate(0.1f);
    }

    @Override
    public void pressBreakPedal() {
        chassis.brake(0.1f);
    }

    @Override
    public void pressLeftButton() {
        chassis.moveLeft(0.1f);
    }

    @Override
    public void pressRightButton() {
        chassis.moveRight(0.1f);
    }

    @Override
    public void moveRightWheel(float angle) {

    }

    @Override
    public void moveLeftWheel(float angle) {

    }

    @Override
    public void pressUpButton() {
        chassis.moveUp(0.1f);
    }

    @Override
    public void pressDownButton() {
        chassis.moveDown(0.1f);
    }

    @Override
    public void printInfo() {
        chassis.printInfo();
    }
}
