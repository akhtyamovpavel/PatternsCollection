package ru.akhcheck.patterns.facade.facades;

import java.util.Map;
import java.util.function.Supplier;
import ru.akhcheck.patterns.builder.Chef;
import ru.akhcheck.patterns.builder.builders.BurgerBuilder;
import ru.akhcheck.patterns.builder.builders.HamburgerBuilder;
import ru.akhcheck.patterns.builder.builders.VegiburgerBuilder;

/**
 * Прячет связку из повара и строителей за двумя понятными методами.
 *
 * <p>Снаружи никто не знает ни того, что бургер собирается по шагам, ни
 * порядка этих шагов. Наружу торчит одно: какой бургер приготовить.
 */
public class BurgerFacade {
    private static final Map<String, Supplier<BurgerBuilder>> BUILDERS = Map.of(
            "hamburger", HamburgerBuilder::new,
            "vegiburger", VegiburgerBuilder::new
    );

    private final Chef chef = new Chef();

    public String createHamburger() {
        return create(new HamburgerBuilder());
    }

    public String createVegiburger() {
        return create(new VegiburgerBuilder());
    }

    public String createBurger(String burgerType) {
        Supplier<BurgerBuilder> supplier = BUILDERS.get(burgerType);
        if (supplier == null) {
            throw new IllegalArgumentException("unknown burger type: " + burgerType);
        }
        return create(supplier.get());
    }

    private String create(BurgerBuilder builder) {
        chef.setBuilder(builder);
        return chef.Cook().toString();
    }
}
