package ru.akhcheck.patterns.mediator.dispatcher;

import java.util.ArrayList;
import java.util.List;
import ru.akhcheck.patterns.mediator.vehicles.Vehicle;

/**
 * Держит полосу и решает, кому её отдать.
 *
 * <p>Вся логика взаимодействия собрана здесь. Если бы самолёты договаривались
 * напрямую, каждому пришлось бы знать про остальных, и число связей росло бы
 * как квадрат числа участников.
 */
public class PlaneDispatcher implements Dispatcher {
    private final List<Vehicle> planes = new ArrayList<>();
    private Vehicle runwayTakenBy;

    public void addPlane(Vehicle plane) {
        planes.add(plane);
        plane.setDispatcher(this);
    }

    @Override
    public boolean notify(Vehicle vehicle, String message) {
        if ("request_landing".equals(message)) {
            if (runwayTakenBy == null) {
                runwayTakenBy = vehicle;
                System.out.println("  dispatcher: runway is given to " + vehicle.getName());
                return true;
            }
            System.out.println(
                    "  dispatcher: runway is taken by " + runwayTakenBy.getName()
                            + ", " + vehicle.getName() + " waits"
            );
            return false;
        }

        if ("runway_free".equals(message)) {
            if (runwayTakenBy == vehicle) {
                runwayTakenBy = null;
                System.out.println(
                        "  dispatcher: runway is free again after " + vehicle.getName()
                );
            }
            return true;
        }

        return false;
    }
}
