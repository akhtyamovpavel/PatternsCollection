package ru.akhcheck.patterns.singleton;

public class MainSingleton {
    public static void main(String[] args) {
        Singleton instance1 = Singleton.getInstance();
        Singleton instance2 = Singleton.getInstance();

        System.out.println(
            instance2.equals(instance1)
        );
    }
}
