package ru.akhcheck.patterns.decorator.notifiers;

/** Добавляет отправку письмом поверх вложенного отправителя. */
public class EmailNotifier extends DecoratorNotifier {
    private final String address;

    public EmailNotifier(Notifier notifier, String address) {
        super(notifier);
        this.address = address;
    }

    @Override
    public void notify(String message) {
        super.notify(message);
        System.out.println("[email to=" + address + "] " + message);
    }
}
