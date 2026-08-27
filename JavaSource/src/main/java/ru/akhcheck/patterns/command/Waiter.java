package ru.akhcheck.patterns.command;

import java.util.ArrayList;
import java.util.List;
import ru.akhcheck.patterns.command.commands.Command;

/**
 * Тот, кто принимает заказ, но не готовит.
 *
 * <p>Официант знает только про интерфейс команды. Кто исполнитель и что именно
 * он сделает, официанту неизвестно, и в этом весь смысл: добавление нового
 * блюда не меняет здесь ни строчки.
 *
 * <p>Счёт и отмена возможны ровно потому, что команды это объекты, которые
 * можно сохранить.
 */
public class Waiter {
    private final List<Command> commands = new ArrayList<>();

    public void setCommand(Command command) {
        commands.add(command);
    }

    public void executeCommands() {
        for (Command command : commands) {
            System.out.println("Order: " + command);
            command.execute();
        }
    }

    public int getBill() {
        int sum = 0;
        for (Command command : commands) {
            sum += command.getPrice();
        }
        return sum;
    }

    public Command cancelLast() {
        if (commands.isEmpty()) {
            return null;
        }
        return commands.remove(commands.size() - 1);
    }
}
