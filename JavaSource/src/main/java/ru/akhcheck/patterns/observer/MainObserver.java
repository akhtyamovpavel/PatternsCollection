package ru.akhcheck.patterns.observer;

/** Точка входа примера наблюдателя. */
public class MainObserver {

    private static void produce(MessageStorage storage, String prefix, int amount) {
        for (int index = 0; index < amount; ++index) {
            storage.pushMessage(prefix + "-" + index);
        }
    }

    public static void main(String[] args) throws InterruptedException {
        MessageStorage storage = new MessageStorage();

        ConsoleObserver console = new ConsoleObserver("console");
        CountingObserver counter = new CountingObserver();

        storage.attach(console);
        storage.attach(counter);

        Thread first = new Thread(() -> produce(storage, "hello", 3));
        Thread second = new Thread(() -> produce(storage, "world", 3));

        first.start();
        second.start();
        first.join();
        second.join();

        System.out.println();
        System.out.println("counter saw messages: " + counter.getCount());

        // Отписываем печать: источник не меняется, а поведение меняется.
        storage.detach(console);
        storage.pushMessage("nobody prints this one");
        System.out.println("counter saw messages: " + counter.getCount());

        System.out.println();
        System.out.println("в очереди осталось: " + storage.readMessages());
    }
}
