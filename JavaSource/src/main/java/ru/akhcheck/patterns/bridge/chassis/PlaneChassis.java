package ru.akhcheck.patterns.bridge.chassis;

public class PlaneChassis implements Chassis {
    private float speed;
    private float rotateAngle;
    private float angle;


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
        this.rotateAngle += angle;
    }

    @Override
    public void moveRight(float angle) {
        this.rotateAngle -= angle;
    }

    @Override
    public void moveUp(float height) {
        this.angle += height;
    }

    @Override
    public void moveDown(float height) {
        this.angle -= angle;
        if (this.angle < 0) {
            this.angle = 0;
        }
    }

    @Override
    public void beep() {
    }

    @Override
    public void printInfo() {
        System.out.println("Type: Plane");
        System.out.println("Rotate: " + this.rotateAngle);
        System.out.println("Speed: " + this.speed);
        System.out.println("MoveAngle: " + this.rotateAngle);
    }

}
