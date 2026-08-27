package ru.akhcheck.patterns.mediator.vehicles;

/** Самолёт: просит полосу у диспетчера и садится, если её дали. */
public class Plane extends Vehicle {
    private PlaneCommand status = PlaneCommand.CONNECTED;

    public Plane(String name) {
        super(name);
    }

    public PlaneCommand getStatus() {
        return status;
    }

    /** Просит полосу и садится, только если её дали. */
    public void land() {
        status = PlaneCommand.WAITING;
        System.out.println(getName() + ": requesting the runway");

        boolean allowed = notifyDispatcher("request_landing");
        if (!allowed) {
            System.out.println(getName() + ": runway is busy, staying in the air");
            return;
        }

        status = PlaneCommand.LANDING;
        System.out.println(getName() + ": landing");
        hasLanded();
    }

    public void hasLanded() {
        status = PlaneCommand.LANDED;
        System.out.println(getName() + ": landed");
        notifyDispatcher("runway_free");
    }
}
