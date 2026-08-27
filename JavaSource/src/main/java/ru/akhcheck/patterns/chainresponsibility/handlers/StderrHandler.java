package ru.akhcheck.patterns.chainresponsibility.handlers;

import java.util.Set;

/** Печатает запись в поток ошибок. */
public class StderrHandler extends BaseHandler {
    public StderrHandler(Set<LogLevel> logLevels) {
        super(logLevels);
    }

    @Override
    protected void process(Log log) {
        System.err.println(log);
    }
}
