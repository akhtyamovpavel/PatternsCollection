package ru.akhcheck.patterns.adapter;

import java.io.IOException;
import java.util.Objects;

public class MainAdapter {
    public static void main(String[] args) throws IOException {
        JsonStorage jsonStorage = new JsonStorage();
        jsonStorage.read(
            Objects.requireNonNull(MainAdapter.class.getClassLoader().getResource("adapter/input.json").getPath())
        );
        jsonStorage.write("output.json");

        YamlStorage yamlStorage = new YamlStorage();
        yamlStorage.read(
                Objects.requireNonNull(MainAdapter.class.getClassLoader().getResource("adapter/input.yaml").getPath())
        );
        yamlStorage.write("output.yaml");

        YamlJsonAdapter storage = new YamlJsonAdapter();
        storage.read(
                Objects.requireNonNull(MainAdapter.class.getClassLoader().getResource("adapter/input.yaml").getPath())
        );
        storage.write("output_yaml.json");
    }
}
