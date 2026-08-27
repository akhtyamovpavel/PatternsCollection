package ru.akhcheck.patterns.chainresponsibility.handlers;

import java.util.Set;
import java.util.function.BiConsumer;

/**
 * Общая часть звена: фильтр по уровню и передача дальше.
 *
 * <p>Наследники переопределяют только process, то есть собственно работу. Обход
 * цепочки и проверка уровня написаны здесь один раз.
 */
public class BaseHandler implements LoggingHandler {
    private final Set<LogLevel> logLevels;
    private LoggingHandler next;
    private BiConsumer<Exception, Log> onError;

    public BaseHandler(Set<LogLevel> logLevels) {
        this.logLevels = logLevels;
    }

    @Override
    public LoggingHandler setNext(LoggingHandler handler) {
        this.next = handler;
        return handler;
    }

    public void setErrorFunction(BiConsumer<Exception, Log> function) {
        this.onError = function;
    }

    @Override
    public void handle(Log log) {
        if (matches(log)) {
            try {
                process(log);
            } catch (Exception error) {
                report(error, log);
            }
        }

        if (next != null) {
            next.handle(log);
        }
    }

    /** Работа звена. Базовое звено ничего не делает намеренно. */
    protected void process(Log log) {
    }

    private boolean matches(Log log) {
        return logLevels.contains(log.getLevel());
    }

    private void report(Exception error, Log log) {
        if (onError != null) {
            onError.accept(error, log);
            return;
        }
        System.out.println("handler failed on " + log + ": " + error.getMessage());
    }
}
