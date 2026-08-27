package ru.akhcheck.patterns.command;

import ru.akhcheck.patterns.command.commands.CreateCocktailCommand;
import ru.akhcheck.patterns.command.commands.CreateSoupCommand;
import ru.akhcheck.patterns.command.cookery.CookPool;

/** Точка входа примера команды. */
public class MainCommand {

    public static void main(String[] args) {
        Waiter waiter = new Waiter();

        waiter.setCommand(new CreateSoupCommand(CookPool.getCook(), "Borsh"));
        waiter.setCommand(new CreateCocktailCommand(CookPool.getBartender(), "Mojito"));
        waiter.setCommand(new CreateSoupCommand(CookPool.getCook(), "Solyanka"));

        // Гость передумал: заказ снимается до того, как что-то приготовлено.
        System.out.println("cancelled: " + waiter.cancelLast());
        System.out.println();

        waiter.executeCommands();

        System.out.println();
        System.out.println("bill: " + waiter.getBill());
    }
}
