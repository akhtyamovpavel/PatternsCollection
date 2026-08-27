package ru.akhcheck.patterns.chainresponsibility.handlers;

/**
 * Звено цепочки.
 *
 * <p>Смысл паттерна в том, что отправитель не знает, кто именно обработает
 * запрос. Он отдаёт его первому звену, а дальше запрос идёт по цепочке, пока
 * кто-нибудь не возьмёт его или пока звенья не кончатся.
 */
public interface LoggingHandler {
    LoggingHandler setNext(LoggingHandler handler);

    void handle(Log log);
}
