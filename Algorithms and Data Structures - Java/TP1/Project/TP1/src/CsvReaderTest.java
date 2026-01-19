import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class CsvReaderTest {

    @Test
    public void testCsvReader() {
        CsvReader csvReader = new CsvReader("testFile.csv");
        Assertions.assertEquals("Value1", csvReader.get("Key1"));
        Assertions.assertEquals("Value2", csvReader.get("Key2"));
        Assertions.assertEquals("Value3", csvReader.get("Key3"));
    }

}






