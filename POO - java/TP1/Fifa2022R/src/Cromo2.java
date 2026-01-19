/**
* class Cromo2
* @version 1
* @author Ricardo Fortuna
* @author Rafael Rio
* @return avaliação
*/


public class Cromo2 {
	private String cromo;
	private int quant;
	
	public Cromo2(String str, int quant) {
		this.setCromo(str);
		this.setQuant(quant);
	}
	
	/**
	* transforma um object em texto
	* @return String
	*/
	public String toString() {
		return ""+cromo+" "+quant;
	}

	/**
	* Inserir valor no cromo
	* @param cromo
	*/
	public void setCromo(String cromo) {
		this.cromo = cromo;
	}

	/**
	* Inserir Quantidade
	* @param quant
	*/
	public void setQuant(int quant) {
		this.quant = quant;
	}
	
	/**
	* receber o valor cromo
	* @return cromo
	*/
	public String getCromo() {
		return cromo;
	}

	/**
	* receber o valor Quantidade
	* @return quant
	*/
	public int getQuant() {
		return quant;
	}
	
	/**
	* compara 2 objectos(cromos)
	* @param cromo
	* @return check flag true se for igual false se for diferente
	*/
	public boolean cromoEquals(Cromo2 cromo){
		boolean check= false;
		
		if(this.getCromo()==cromo.getCromo() && this.getQuant()==cromo.getQuant())
			check=true;
			
		return check;
	}

}
