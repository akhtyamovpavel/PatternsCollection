package ru.akhcheck.patterns.facade;

import ru.akhcheck.patterns.facade.facades.Facade;

/** Точка входа примера фасада. */
public class MainFacade {

    public static void main(String[] args) {
        Facade facade = new Facade();

        System.out.println(facade.createNormalGame() + " is normal game");
        System.out.println(facade.createHardGame() + " is hard game");
        System.out.println(facade.createVegiburger() + " is burger");
    }
}
