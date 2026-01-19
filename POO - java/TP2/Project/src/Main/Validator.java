/**
* interface Validator
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

package Main;

interface Validator <T extends Object> {
	
	public String validate(T x);

	public Boolean IsValid(String validationResult);
}
