/**
* class CsvReader
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;

public class CsvReader extends HashMap<String, String> {
      
    public CsvReader(String fileName) {
        try {
            Scanner scanner = new Scanner(new File(fileName));
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                StringTokenizer tokenizer = new StringTokenizer(line, ",");
                String key = tokenizer.nextToken();
                String value = "";
                while (tokenizer.hasMoreTokens()) {
                    value += tokenizer.nextToken();
                    if (tokenizer.hasMoreTokens()) {
                        value += ",";
                    }
                }
                put(key, value);
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}

