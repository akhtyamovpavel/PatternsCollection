package ru.akhcheck.patterns.adapter;

import org.apache.commons.io.IOUtils;
import org.json.JSONObject;
import org.yaml.snakeyaml.Yaml;

import java.io.*;
import java.util.Map;

public class YamlStorage {
    private Map<String, Object> yamlMapping;

    public void read(String filename) {
        try {
            InputStream inputStream = new FileInputStream(filename);
            Yaml yaml = new Yaml();
            yamlMapping = yaml.load(inputStream);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public Map<String, Object> get() {
        return yamlMapping;
    }

    public void write(String filename) throws IOException {
        PrintWriter out = new PrintWriter(new FileWriter(filename));
        Yaml yaml = new Yaml();
        yaml.dump(yamlMapping, out);
    }
}
