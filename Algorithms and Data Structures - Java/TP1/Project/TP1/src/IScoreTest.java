import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class IScoreTest {

    @Test
    public void testJaccard() {
        double result = IScore.calculateScore("hello", "world", "jaccard");
        assertEquals(0.2857142857142857, result);

        result = IScore.calculateScore("hello", "he", "jaccard");
        assertEquals(0.5, result);

        result = IScore.calculateScore("abcd", "dcba", "jaccard");
        assertEquals(1.0, result);

    }

    @Test
    public void testLevenshtein() {
        double result = IScore.calculateScore("hello", "world", "levenshtein");
        assertEquals(0.6, result);

        result = IScore.calculateScore("hello", "he", "levenshtein");
        assertEquals(0.5714285714285714, result);

        result = IScore.calculateScore("abcd", "dcba", "levenshtein");
        assertEquals(0.5, result);
    }

    @Test
    public void testhamming() {
        double result = IScore.calculateScore("hello", "world", "hamming");
        assertEquals(4, result);

        result = IScore.calculateScore("hello", "he", "hamming");
        assertEquals(0.0, result);

        result = IScore.calculateScore("abcd", "dcba", "hamming");
        assertEquals(4.0, result);
    }
    

    
    
    
    @Test
    public void testHamming() {
        String s1 = "hello";
        String s2 = "helo";
        double expectedDistance = 0;

        double actualDistance = IScore.hamming(s1, s2);

        assertEquals(expectedDistance, actualDistance);
    }
    
    @Test
    public void testCalculateScoreWithCoisine() {
        String s1 = "hello world";
        String s2 = "hello there";
        String metodo = "coisine";
        double expectedScore = 0.9772727272727273;

        double actualScore = IScore.calculateScore(s1, s2, metodo);

        assertEquals(expectedScore, actualScore);
    }
}