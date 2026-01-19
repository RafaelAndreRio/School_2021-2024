package Testes_Unitarios_Main;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import Body.CsvReader;

class CsvReaderTest {

	@Test
	void test() {

			CsvReader csvReader = new CsvReader(
					"D:\\Work Spasce\\Eclipse\\TP2_TestesUnis_TestarGraph\\src\\Testes_Unitarios_Main\\testFile.CSV",
					",");

			Assertions.assertEquals("Key2", csvReader.get(0).get(0));
			Assertions.assertEquals("Value2", csvReader.get(0).get(1));

			Assertions.assertEquals("Key1", csvReader.get(1).get(0));
			Assertions.assertEquals("Value1", csvReader.get(1).get(1));

			Assertions.assertEquals("Key3", csvReader.get(2).get(0));
			Assertions.assertEquals("Value3", csvReader.get(2).get(1));
	}
}
