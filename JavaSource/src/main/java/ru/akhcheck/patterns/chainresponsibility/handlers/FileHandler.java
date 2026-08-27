package ru.akhcheck.patterns.chainresponsibility.handlers;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.Set;

/** Пишет запись в файл. */
public class FileHandler extends BaseHandler {
    private final Path path;

    public FileHandler(Path path, Set<LogLevel> logLevels) {
        super(logLevels);
        this.path = path;
    }

    @Override
    protected void process(Log log) {
        try {
            Files.writeString(
                    path,
                    log + System.lineSeparator(),
                    StandardCharsets.UTF_8,
                    StandardOpenOption.CREATE,
                    StandardOpenOption.APPEND
            );
        } catch (IOException error) {
            throw new IllegalStateException("cannot write to " + path, error);
        }
    }
}
