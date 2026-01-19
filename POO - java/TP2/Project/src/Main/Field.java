/**
* class Field
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/
package Main;

public class Field <T extends Object> {
	
	public String id;				// Cliente Key Do HashMap
	public T valueField;			// Cliente valor do hashMap
	public Validator[] validators;

	public Field(String id, Validator[] validators) {
		this.id = id;
		this.validators = validators;
	}
	/**
	* Inserir valor do tipo T (Generico)
	* @param valueField do hashmap
	*/
	public void setData(T x) {
		this.valueField=x;
	}
	/**
	* retorna a variável x do tipo T(Generico)
	* @return valueField do hashmap
	*/
	public T getData(){
	      return this.valueField;
	    }
	/**
	* retorna a variável x do tipo T(Generico)
	* @return ID do hashmap
	*/
	public String getId(){
	      return this.id;
	    }
	/**
	* transforma um object em texto
	* @return String
	*/
	 public String toString(){
	      return String.valueOf(this.getData());
	   }
}
