package Main;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import Main.Field;
import Main.Required;
import Main.StringField;
import Main.Validator;

public class StringFieldTest {
	
	Field validar2 = new StringField("Email", new Validator[] { new Required() });

	@Test
	final void testStringField() {
		
		validar2.setData("ismat@gmail.com");
		
		assertEquals(validar2.getData(), "ismat@gmail.com");
		assertEquals(validar2.validators[0].validate(validar2.getData()), "True");
		assertEquals(validar2.validators[0].validate(""), "Error: Value empty");
	}
}
