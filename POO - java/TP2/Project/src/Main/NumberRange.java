/**
* class NumberRange
* @version 1
* @author Ricardo Fortuna
* @author Rafael Rio
*/

package Main;

public class NumberRange implements Validator <Integer> {
	
	final int min;
	final int max;
	
	/**
	 * construtor insere os valores nos atributos
	 * @param min valor minimo do intervalo
	 * @param max valor maximo do intervalo
	 */
	public NumberRange(int x, int y) {
		this.min = x;
		this.max = y;
	} 
	
	/**
	 * metodo de validaçao retorna o Erro em string ou True em string
	 * @return String do erro, ou "TRUE"
	 * @see IsValid
	 */
	
	public String validate(Integer x) {
		if(x < this.min || x > this.max) return "Error: value not in range";
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
