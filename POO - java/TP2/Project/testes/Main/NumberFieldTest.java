package Main;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import Main.Field;
import Main.NumberField;
import Main.NumberRange;
import Main.Validator;

public class NumberFieldTest {
	
	Field validar3 = new NumberField("Age", new Validator[] { new NumberRange(16, 99) });

	@Test
	public final void testNumberField() {

		validar3.setData(16);
		assertEquals(validar3.getData(), 16);		
		assertEquals(validar3.validators[0].validate(validar3.getData()), "True");
		assertEquals(validar3.validators[0].validate(4), "Error: value not in range");
	}

}
