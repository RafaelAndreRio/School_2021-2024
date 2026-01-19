/**
* class NumberField
* @version 1
* @author Ricardo Fortuna
* @author Rafael Rio
*/
package Main;

public class NumberField extends Field <Integer>{
	
	/**
	 * construtor insere os valores nos atributos
	 * @param id
	 * @param validators
	 */
	
	public NumberField(String id, Validator[] validators) {
		super(id, validators);

	}	
}
