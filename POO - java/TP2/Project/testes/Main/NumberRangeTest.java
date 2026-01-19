package Main;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import Main.NumberRange;

public class NumberRangeTest {

	NumberRange validar = new NumberRange(2, 4);

	@Test
	final void testNumberRange() {
		assertEquals(validar.min, 2);
		assertEquals(validar.max, 4);
	}

	@Test
	final void testValidateTrue() {
		int idade=3;
		assertEquals(validar.validate(idade), "True");
	}

	@Test
	final void testValidateMenor() {
		int idade=0;
		assertEquals(validar.validate(idade), "Error: value not in range");
	}
	@Test
	final void testValidateMaior() {
		int idade=9;
		assertEquals(validar.validate(idade), "Error: value not in range");
	}
	
	
	@Test
	void testIsValidTrue() {
		String str = "True";
		assertEquals(validar.IsValid(str),true);
	}
	
	@Test
	void testIsValidFalse() {
		String str = "Error";
		assertEquals(validar.IsValid(str),false);
	}

}
