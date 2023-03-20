package ru.akhcheck.patterns.bridge.chassis;

public class CarChassis implements Chassis {

    private float speed;
    private float moveAngle;

    @Override
    public void accelerate(float speed) {
        this.speed += speed;
    }

    @Override
    public void brake(float speed) {
        this.speed -= speed;
        if (this.speed < 0) {
            this.speed = 0;
        }
    }

    @Override
    public void moveLeft(float angle) {
        this.moveAngle += angle;
    }

    @Override
    public void moveRight(float angle) {
        this.moveAngle -= angle;
    }

    @Override
    public void moveUp(float height) {

    }

    @Override
    public void moveDown(float height) {

    }

    @Override
    public void beep() {
        System.out.println("Beep");
    }

    @Override
    public void printInfo() {
        System.out.println("Type: Car");
        System.out.println("Speed: " + speed);
        System.out.println("Angle: " + moveAngle);
    }
}
