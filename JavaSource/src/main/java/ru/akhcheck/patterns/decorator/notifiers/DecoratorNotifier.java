package ru.akhcheck.patterns.decorator.notifiers;

/**
 * Базовая обёртка: держит вложенный отправитель и передаёт ему вызов.
 *
 * <p>Сама по себе она ничего не добавляет, и в этом смысл: наследники
 * дописывают только своё поведение, а передачу дальше получают готовой.
 */
public abstract class DecoratorNotifier implements Notifier {
    private final Notifier notifier;

    protected DecoratorNotifier(Notifier notifier) {
        this.notifier = notifier;
    }

    @Override
    public void notify(String message) {
        notifier.notify(message);
    }
}
