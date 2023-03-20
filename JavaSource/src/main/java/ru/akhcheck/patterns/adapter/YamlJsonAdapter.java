package ru.akhcheck.patterns.adapter;

import org.json.JSONObject;

import java.io.IOException;
import java.util.Map;

public class YamlJsonAdapter extends YamlStorage {

    private JsonStorage adapter = new JsonStorage();

    private JSONObject yamlToJson(Map<String, Object> items) {
        return new JSONObject(items);
    }
    @Override
    public void write(String filename) throws IOException {
        JSONObject json = yamlToJson(this.get());
        adapter.setJson(json);
        adapter.write(filename);
    }
}
