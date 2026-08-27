package ru.akhcheck.patterns.memento;

import java.util.TreeSet;

/** Точка входа примера хранителя. */
public class MainMemento {

    public static void main(String[] args) {
        Originator game = new Originator();
        Caretaker caretaker = new Caretaker(game);

        game.startNewGame();
        game.increaseLevel();
        System.out.println("before first save");
        game.showCurrentProgress();
        caretaker.save("first_save");

        game.increaseLevel();
        game.increaseLevel();
        System.out.println("after two more levels");
        game.showCurrentProgress();
        caretaker.save("second_save");

        System.out.println("saves: " + new TreeSet<>(caretaker.getSaves()));

        caretaker.load("first_save");
        System.out.println("after loading first save");
        game.showCurrentProgress();
    }
}
