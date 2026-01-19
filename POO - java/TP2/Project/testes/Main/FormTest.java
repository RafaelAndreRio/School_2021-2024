package Main;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.ArrayList;
import java.util.HashMap;

import org.junit.jupiter.api.Test;

import Main.Field;
import Main.Length;
import Main.NumberField;
import Main.NumberRange;
import Main.Required;
import Main.StringField;
import Main.Validator;

public class FormTest extends HashMap<String, Field>{

	
	ArrayList<String> errors = new ArrayList<String>();
	UsernameForm form = new UsernameForm();

	private String htmlForm;
	private String json;
	

	
	@Test
	public final void testForm() {		
		
		form.put("username", new StringField("Username",new Validator[]{new Length(3)}));
		form.put("email", new StringField("Email", new Validator[]{new Required()}));
		form.put("age", new NumberField("Age", new Validator[]{new NumberRange(16,99)}));
		

		
		form.get("username").setData("tia");
		form.get("email").setData("tia@gmail.com");
		form.get("age").setData(16);

	}
	

	@Test
	public final void testValidate() {
		
		for (String key : keySet()) {
			var fieldToValidate = get(key);
			
			ValidateField(fieldToValidate);
		}
	}

	@Test
	private void ValidateField(Field fieldToValidate) {
		Validator[] fieldValidators = fieldToValidate.validators;

		if (fieldValidators != null) {
			for (Validator validator : fieldValidators) {
				String validationResult = validator.validate(fieldToValidate.getData());

				if (!validator.IsValid(validationResult)) {
					errors.add(validationResult);
				}
			}
		}
	}
	
	
	@Test
	public final void testContent() {
	
		
		htmlForm = "<form>\n";

		form.forEach((key, value) -> {
			htmlForm = htmlForm + "\t<label for='" + key.toString() + "'>" + key.toString() + ":</label>\n";
			htmlForm = htmlForm + "\t<label name='" + key.toString() + "' type='" + "' value='" + value.toString()
					+ "'/><br>\n";
		});
		htmlForm = htmlForm + "</form>";
	
		String contentIgual="<form>\n"
			+"\t<label for='email'>email:</label> \n"
			+ "\t<label name='email' type='' value='tia@gmail.com'/><br>\n"
			+ "\t<label for='age'>age:</label>\n"
			+"\t<label name='age' type='' value='16'/><br>\n"
			+"\t<label for='username'>username:</label>\n"
			+"\t<label name='username' type='' value='tia'/><br>\n"
		+"</form>";

		assertEquals(contentIgual, htmlForm);		

		
	}

	@Test
	public final void testJson() {
		
		json = "{";
		form.forEach((key, value) -> {
			json = json + "'" + key.toString() + "':'";
			json = json + value.getData() + "',";
		});
		
		json = json + "}";
		
		String jsonIgual="{'email':'tia@gmail.com','age':'16','username':'tia',}";
		
	
		assertEquals(jsonIgual, json);		

	}

}
