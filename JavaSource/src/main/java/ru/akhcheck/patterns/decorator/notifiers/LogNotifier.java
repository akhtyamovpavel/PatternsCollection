package ru.akhcheck.patterns.decorator.notifiers;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;

/** Основа цепочки: пишет сообщение в файл и никого не оборачивает. */
public class LogNotifier implements Notifier {
    private final Path path;

    public LogNotifier(Path path) {
        this.path = path;
    }

    @Override
    public void notify(String message) {
        try {
            Files.writeString(
                    path,
                    message + System.lineSeparator(),
                    StandardCharsets.UTF_8,
                    StandardOpenOption.CREATE,
                    StandardOpenOption.APPEND
            );
        } catch (IOException error) {
            throw new IllegalStateException("cannot write to " + path, error);
        }
    }
}
