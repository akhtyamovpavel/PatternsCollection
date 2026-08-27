package ru.akhcheck.patterns.facade.facades;

/**
 * Фасад над двумя другими фасадами.
 *
 * <p>Показывает, что фасады складываются: каждый следующий уровень убирает ещё
 * часть подробностей. Наружу остаются три действия, за которыми стоят
 * строители, повар, фабрики комнат и сами комнаты.
 */
public class Facade {
    private final IsaacFacade isaacFacade = new IsaacFacade();
    private final BurgerFacade burgerFacade = new BurgerFacade();

    public String createNormalGame() {
        return isaacFacade.createGame("normal");
    }

    public String createHardGame() {
        return isaacFacade.createGame("hard");
    }

    public String createVegiburger() {
        return burgerFacade.createVegiburger();
    }
}
