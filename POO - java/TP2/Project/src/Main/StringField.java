/**
* class StringField
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

package Main;

public class StringField extends Field {
	
	/**
	 * construtor insere os valores nos atributos
	 * @param id 
	 * @param validators
	 */
	public StringField(String id, Validator[] validators) {
		super(id,validators);
	}
}
