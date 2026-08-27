package ru.akhcheck.patterns.chainresponsibility;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import ru.akhcheck.patterns.chainresponsibility.handlers.BaseHandler;
import ru.akhcheck.patterns.chainresponsibility.handlers.DivisionZeroHandler;
import ru.akhcheck.patterns.chainresponsibility.handlers.FileHandler;
import ru.akhcheck.patterns.chainresponsibility.handlers.Log;
import ru.akhcheck.patterns.chainresponsibility.handlers.LogLevel;
import ru.akhcheck.patterns.chainresponsibility.handlers.StderrHandler;

/** Точка входа примера цепочки обязанностей. */
public class MainChainResponsibility {

    public static void main(String[] args) throws IOException {
        Path logPath = Path.of("chain.log");
        Files.deleteIfExists(logPath);

        // Цепочка собирается вызовами setNext, каждый возвращает следующее звено.
        BaseHandler root = new BaseHandler(LogLevel.all());
        root.setErrorFunction(MainChainResponsibility::reportError);

        DivisionZeroHandler broken = new DivisionZeroHandler(LogLevel.all());
        broken.setErrorFunction(MainChainResponsibility::reportError);

        root.setNext(broken)
                .setNext(new FileHandler(logPath, LogLevel.all()))
                .setNext(new StderrHandler(LogLevel.problems()));

        List<Log> records = List.of(
                new Log(LogLevel.DEBUG, "cache warmed up"),
                new Log(LogLevel.INFO, "request handled"),
                new Log(LogLevel.ERROR, "database is unreachable")
        );
        for (Log record : records) {
            System.out.println("--- отправляем: " + record);
            root.handle(record);
        }

        System.out.println();
        System.out.println("в файл попало всё, потому что у него уровни all:");
        System.out.println(Files.readString(logPath, StandardCharsets.UTF_8).strip());
        Files.deleteIfExists(logPath);
    }

    private static void reportError(Exception error, Log log) {
        System.out.println(
                "звено упало на записи " + log + ", но цепочка продолжила: " + error.getMessage()
        );
    }
}
