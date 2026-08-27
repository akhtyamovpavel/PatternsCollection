package ru.akhcheck.patterns.decorator.notifiers;

/**
 * Общий вид отправителя уведомлений.
 *
 * <p>Ради этого интерфейса паттерн и работает: обёртка снаружи выглядит так же,
 * как то, что она обернула, поэтому обёртки складываются в цепочку любой длины
 * и в любом порядке.
 */
public interface Notifier {
    void notify(String message);
}
