package Main;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import Main.Required;

public class RequiredTest {

	Required teste = new Required();
	

	@Test
	final void testValidateTrue() {
		String validar = "True";
		assertEquals(teste.validate(validar),"True");
	}

	@Test
	final void testValidateFalse() {
		String validar ="";
		assertEquals(teste.validate(validar),"Error: Value empty");
	}
	
	@Test
	final void testValidateNull() {
		String validar = null;
		assertEquals(teste.validate(validar),"Error: Value empty");
	}
	
	@Test
	void testIsValidTrue() {
		String str = "True";
		assertEquals(teste.IsValid(str),true);
	}
	
	@Test
	void testIsValidFalse() {
		String str = "Error";
		assertEquals(teste.IsValid(str),false);
	}

}
