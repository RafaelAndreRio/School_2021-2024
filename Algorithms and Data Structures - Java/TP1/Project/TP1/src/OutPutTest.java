import org.junit.Test;
import static org.junit.Assert.*;
import java.util.ArrayList;

public class OutPutTest {
    private final static String PATH1 = "D:\\Work Spasce\\Eclipse\\TP1\\fileTeste1.CSV";
    private final static String PATH2 = "D:\\Work Spasce\\Eclipse\\TP1\\fileTeste2.CSV";
    private final static String ALGORITHM_USED = "levenshtein";

    @Test
    public void testOutput() {
        // Arrange
        ArrayList<ArrayList<String>> expectedBoard = new ArrayList<ArrayList<String>>();
        ArrayList<String> row1 = new ArrayList<String>();
        row1.add("Name");
        row1.add("Name");
        row1.add("1.0");
        row1.add("John");
        row1.add("Jane");
        expectedBoard.add(row1);
        ArrayList<String> row2 = new ArrayList<String>();
        row2.add("Age");
        row2.add("Age");
        row2.add("1.0");
        row2.add("30");
        row2.add("30");
        expectedBoard.add(row2);
        ArrayList<String> row3 = new ArrayList<String>();
        row3.add("Salary");
        row3.add("Salary");
        row3.add("0.8");
        row3.add("2000");
        row3.add("2500");
        expectedBoard.add(row3);

        
        ArrayList<ArrayList<String>> actualBoard = new ArrayList<ArrayList<String>>();
        
        actualBoard=OutPut.mostrar(PATH1, PATH2, ALGORITHM_USED);


        assertEquals(expectedBoard, actualBoard);
    }
}