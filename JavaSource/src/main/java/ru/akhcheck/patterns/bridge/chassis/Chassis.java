package ru.akhcheck.patterns.bridge.chassis;

public interface Chassis {
    void accelerate(float speed);
    void brake(float speed);
    void moveLeft(float angle);
    void moveRight(float angle);
    void moveUp(float height);
    void moveDown(float height);
    void beep();
    void printInfo();
}
