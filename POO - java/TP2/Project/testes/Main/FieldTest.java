package Main;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import Main.Field;
import Main.Length;
import Main.NumberField;
import Main.NumberRange;
import Main.Required;
import Main.StringField;
import Main.Validator;

public class FieldTest  <T extends Object>{

	Field validar1 = new StringField("Username", new Validator[] { new Length(3) });
	Field validar2 = new StringField("Email", new Validator[] { new Required() });
	Field validar3 = new NumberField("Age", new Validator[] { new NumberRange(16, 99) });

	@Test
	public final void testField() {

		// setData
		validar1.setData("Tia");
		validar2.setData("ismat@gmail.com");
		validar3.setData(16);

		// GetID
		assertEquals(validar1.getId(), "Username");
		assertEquals(validar2.getId(), "Email");
		assertEquals(validar3.getId(), "Age");

		// GetData
		assertEquals(validar1.getData(), "Tia");
		assertEquals(validar2.getData(), "ismat@gmail.com");
		assertEquals(validar3.getData(), 16);

		// Teste de requesitos True
		assertEquals(validar1.validators[0].validate(validar1.getData()), "True");
		assertEquals(validar2.validators[0].validate(validar2.getData()), "True");
		assertEquals(validar3.validators[0].validate(validar3.getData()), "True");

		// Teste de requesitos False
		assertEquals(validar1.validators[0].validate("Ti"), "Error: less than min");
		assertEquals(validar2.validators[0].validate(""), "Error: Value empty");
		assertEquals(validar3.validators[0].validate(4), "Error: value not in range");
	}

	@Test
	public final void testToString() {
		validar1.setData("Tia");

		assertEquals(validar1.toString(), "Tia");
	}

}
