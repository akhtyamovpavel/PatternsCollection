package ru.akhcheck.patterns.adapter;

import org.apache.commons.io.IOUtils;
import org.json.JSONObject;

import java.io.*;

public class JsonStorage {
    private JSONObject json;

    public void read(String filename) {
        try {
            InputStream inputStream = new FileInputStream(filename);
            String jsonText = IOUtils.toString(inputStream, "UTF-8");
            json = new JSONObject(jsonText);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void setJson(JSONObject json) {
        this.json = json;
    }
    public void write(String filename) throws IOException {
        PrintWriter out = new PrintWriter(new FileWriter(filename));
        out.write(json.toString());
        out.flush();
        out.close();
    }
}
