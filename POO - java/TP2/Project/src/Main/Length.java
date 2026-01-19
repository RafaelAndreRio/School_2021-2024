/**
* class Length
* @version 1
* @author Ricardo Fortuna
* @author Rafael Rio
*/

package Main;

public class Length implements Validator <String> {
	
	private final int minSize;
	
	public Length(int x) {
		this.minSize = x;
	}
	
	/**
	 * retorna o valor do minSize
	 * @return inteiro que representa o minimo do validador
	 */
	
	public int get() {
		return this.minSize;
	}
	
	/**
	 * metodo de validaçao retorna o Erro em string ou True em string
	 * @return String do erro, ou "TRUE"
	 * @see IsValid
	 */
	
	public String validate(String str) {
		
		if(str.length() < this.minSize) return "Error: less than min";
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
