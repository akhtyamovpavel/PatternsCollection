package ru.akhcheck.patterns.bridge;

import ru.akhcheck.patterns.bridge.chassis.CarChassis;
import ru.akhcheck.patterns.bridge.chassis.PlaneChassis;
import ru.akhcheck.patterns.bridge.wheels.Gamepad;
import ru.akhcheck.patterns.bridge.wheels.PlaneWheel;

public class MainBridge {
    public static void main(String[] args) {
        CarChassis carChassis = new CarChassis();

        Gamepad gamepad = new Gamepad(carChassis);
        gamepad.pressUpButton();

        for (int i = 0; i < 10; ++i) {
            gamepad.pressGasPedal();
            gamepad.pressDownButton();
            gamepad.pressGasPedal();
        }
        gamepad.pushWheel();
        gamepad.printInfo();

        CarChassis planeCarChassis = new CarChassis();

        PlaneWheel planeWheel = new PlaneWheel(planeCarChassis);

        for (int index = 0; index < 10; ++index) {
            planeWheel.pullWheel();
        }

        planeWheel.printInfo();

        PlaneChassis planeChassis = new PlaneChassis();
        PlaneWheel realPlaneWheel = new PlaneWheel(planeChassis);
        for (int index = 0; index < 10; ++index) {
            realPlaneWheel.pullWheel();
        }

        realPlaneWheel.printInfo();
    }
}
