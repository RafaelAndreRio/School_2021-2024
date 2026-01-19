/**
* class Required
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

package Main;
public class Required implements Validator <String> {
	
	public Required() {
		
	}
	
	/**
	 * metodo de validaçao retorna o Erro em string ou True em string
	 * @return String do erro, ou "TRUE"
	 * @see IsValid
	 */
	
	public String validate(String str) {
		
		if(str == null) return "Error: Value empty";
		else if(str.length() <= 0) return "Error: Value empty";
		else return "True";
	}

	
	/**
	 * Converte o metodo anterior em string para Booleano
	 *  @return true or false (boolean)
	 */
	public Boolean IsValid(String validationResult) {
		return validationResult == "True";
	}
}
