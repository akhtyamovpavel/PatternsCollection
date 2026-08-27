package ru.akhcheck.patterns.decorator;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import ru.akhcheck.patterns.decorator.notifiers.EmailNotifier;
import ru.akhcheck.patterns.decorator.notifiers.LogNotifier;
import ru.akhcheck.patterns.decorator.notifiers.Notifier;
import ru.akhcheck.patterns.decorator.notifiers.TelegramNotifier;

/** Точка входа примера декоратора. */
public class MainDecorator {

    public static void main(String[] args) throws IOException {
        Path logPath = Path.of("notifications.log");
        Files.deleteIfExists(logPath);

        // Цепочка собирается снаружи внутрь: письмо оборачивает мессенджер,
        // мессенджер оборачивает запись в файл. Порядок задаёт порядок отправки.
        Notifier notifier = new EmailNotifier(
                new TelegramNotifier(new LogNotifier(logPath), "42"),
                "oncall@example.com"
        );
        notifier.notify("service is down");

        System.out.println();
        System.out.println("Тот же набор, но собранный иначе:");

        // Ни один класс не изменился, изменился только порядок обёрток.
        Notifier another = new TelegramNotifier(
                new EmailNotifier(new LogNotifier(logPath), "team@example.com"),
                "7"
        );
        another.notify("service is back");

        System.out.println();
        System.out.println("в файле оказалось:");
        System.out.println(Files.readString(logPath, StandardCharsets.UTF_8).strip());
        Files.deleteIfExists(logPath);
    }
}
