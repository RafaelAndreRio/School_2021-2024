/**
* interface UsernameForm
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

package Main;
class UsernameForm extends Form{

	private static final long serialVersionUID = 1L;

	UsernameForm(){
		super();
		this.put("username", new StringField("Username",new Validator[]{new Length(3)}));
		this.put("email", new StringField("Email", new Validator[]{new Required()}));
		this.put("age", new NumberField("Age", new Validator[]{new NumberRange(16,99)}));
	}
}
