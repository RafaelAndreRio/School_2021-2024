package Main;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import Main.Length;

public class LengthTest {

	Length validar = new Length(3);

	@Test
	public void testget() {
		assertEquals(validar.get(),3);
	}
	
	
	@Test
	public void testValidateTrue() {
		String str = "Tia";
		assertEquals(validar.validate(str),"True");
	}

	@Test
	public void testValidateFalse() {
		String str1 = "Ti";
		assertEquals(validar.validate(str1),"Error: less than min");
	}

	@Test
	public void testIsValidTrue() {
		String str = "True";
		assertEquals(validar.IsValid(str),true);
	}
	
	@Test
	public void testIsValidFalse() {
		String str = "Error";
		assertEquals(validar.IsValid(str),false);
	}
	

}
