/**
* class Form
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

package Main;
import java.util.ArrayList;
import java.util.HashMap;

public class Form extends HashMap<String, Field> {

	ArrayList<String> errors = new ArrayList<String>();
	private String htmlForm;
	private String json;

	Form() {} 
	
	public ArrayList<String> validate() {

		for (String key : keySet()) {
			var fieldToValidate = get(key);
			ValidateField(fieldToValidate);
		}
		return errors;
		}

	/**
	* ValidateField um Metodo privado que testa se deu erro
	* @return String
	*/
	
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
	
	/**
	* constroi o outPut como se fosse um htmlForm
	* @return String
	*/
	
	public String content() {// conteudo inserido

		htmlForm = "<form>\n";

		this.forEach((key, value) -> {
			htmlForm = htmlForm + "\t<label for='" + key.toString() + "'>" + key.toString() + ":</label>\n";
			htmlForm = htmlForm + "\t<label name='" + key.toString() + "' type='" + "' value='" + value.toString()
					+ "'/><br>\n";});
		htmlForm = htmlForm + "</form>";
		return htmlForm;
	} 
	
	/**
	*output dos parametros que nao foram respeitados ao inserir no UsernameField
	* @return String
	*/
	
	public String json() {
		json = "{";
		this.forEach((key, value) -> {
			json = json + "'" + key.toString() + "':'";
			json = json + value.getData() + "',";
		});
		
		json = json + "}";

		return json;
	} // show conteudo {'email':'','age':13,'username':'ti'}

}
