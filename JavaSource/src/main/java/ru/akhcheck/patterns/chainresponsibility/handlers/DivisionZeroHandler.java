package ru.akhcheck.patterns.chainresponsibility.handlers;

import java.util.Set;

/**
 * Звено, которое намеренно падает.
 *
 * <p>Нужно, чтобы показать: сбой одного звена не рвёт цепочку. Остальные звенья
 * отработают, а про ошибку сообщит заданная функция.
 */
public class DivisionZeroHandler extends BaseHandler {
    public DivisionZeroHandler(Set<LogLevel> logLevels) {
        super(logLevels);
    }

    @Override
    protected void process(Log log) {
        int zero = 0;
        System.out.println(1 / zero);
    }
}
