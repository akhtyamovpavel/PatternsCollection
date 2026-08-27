package ru.akhcheck.patterns.chainresponsibility.handlers;

import java.util.EnumSet;
import java.util.Set;

/** Уровни записи. Каждое звено берёт себе только нужные. */
public enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR;

    public static Set<LogLevel> all() {
        return EnumSet.allOf(LogLevel.class);
    }

    public static Set<LogLevel> problems() {
        return EnumSet.of(WARNING, ERROR);
    }
}
