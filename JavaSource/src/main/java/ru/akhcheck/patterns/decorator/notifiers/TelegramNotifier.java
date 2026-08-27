package ru.akhcheck.patterns.decorator.notifiers;

/**
 * Добавляет отправку в мессенджер поверх вложенного отправителя.
 *
 * <p>Настоящий клиент здесь заменён печатью: пример должен запускаться без
 * внешних зависимостей и без ключей.
 */
public class TelegramNotifier extends DecoratorNotifier {
    private final String chatId;

    public TelegramNotifier(Notifier notifier, String chatId) {
        super(notifier);
        this.chatId = chatId;
    }

    @Override
    public void notify(String message) {
        super.notify(message);
        System.out.println("[telegram chat=" + chatId + "] " + message);
    }
}
