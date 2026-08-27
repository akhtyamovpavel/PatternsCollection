package ru.akhcheck.patterns.chainresponsibility.handlers;

/** Запись, которая идёт по цепочке. */
public final class Log {
    private final LogLevel level;
    private final String message;

    public Log(LogLevel level, String message) {
        this.level = level;
        this.message = message;
    }

    public LogLevel getLevel() {
        return level;
    }

    public String getMessage() {
        return message;
    }

    @Override
    public String toString() {
        return "[" + level.name().toLowerCase() + "] " + message;
    }
}
