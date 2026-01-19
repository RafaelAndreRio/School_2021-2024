import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class MainTest {
	
	private Main main;
	
	String[] args;
	@Test
	@DisplayName("Teste true")
	void testMainArgsCorreto() {
		String[] args = {"file1.csv", "file2.csv", "algoritmo"};
		assertDoesNotThrow(() -> Main.main(args));
	}

	
}