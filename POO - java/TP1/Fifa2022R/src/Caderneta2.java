/**
* class Caderneta2
* @version 1
* @author Ricardo Fortuna
* @author Rafael Rio
* @return avaliação
*/





public class Caderneta2 {
	int id;
	Cromo2 cromo[];

	public Caderneta2(Cromo2 cromo[], int id) {
		this.setCromo(cromo);
		this.setID(id);
	}
	
	/**
	*Inserir valor no cromo
	* @param Array de cromos
	*/
	public void setCromo(Cromo2 cromo[]) {
		this.cromo = cromo;
	}

	/**
	*Inserir valor de ID
	* @param numero inteiro
	*/
	public void setID(int id) {
		this.id = id;
	}
	
	/**
	* devolve o array de cromos
	* @return Array de cromos
	*/
	public Cromo2[] getCromo() {
		return cromo;
	}
	
	/**
	* devolve o id do cromo
	* @return ID do cromo
	*/
	public int getID() {
		return this.id;
	}

	/**
	* Compara 2 cadernetas
	* @param Caderneta -> array de cromos
	* @return true se iguais, false se diferentes
	*/
	public boolean cadernetaEquals(Caderneta2 caderneta) {
		boolean check = false;

		if (this.getCromo() == caderneta.getCromo() && this.getID() == caderneta.getID())
			check = true;

		return check;
	}

	/**
	* Analisa a quantidade de trocas no grupo de amigos
	* @param amigos para contar a quantidade de possiveis trocas entre eles
	* @return listaAmigos devolve o array das possiveis trocas, o index corresponde ao index do amigo
	*/
	public int[] verQuantidadeTrocas(Caderneta2[] amigo) {

		int[] listaAmigos = new int[amigo.length];
		for (int i = 0; i < amigo.length; i++) {
			int count1 = verCromosFalta(this, amigo[i]);
			int count2 = verCromosFalta(amigo[i], this);
			listaAmigos[i] = (count1 > count2) ? count2 : count1;
		}
		return listaAmigos;
	}

	/**
	* Conta a possibilidades de receber cromos da cadernetaB para cadernetaA
	* @param cadernetaA user que recebe
	* @param cadernetaB user que dá
	* @return contador de possiveis trocas
	*/
	public int verCromosFalta(Caderneta2 cadernetaA, Caderneta2 cadernetaB) {

		int contador = 0;
		for (int k = 0; k < cadernetaB.cromo.length; k++) {
			if (cadernetaA.cromo[k].getQuant() == 0 && cadernetaB.cromo[k].getQuant() > 1) {
				contador++;
			}
		}
		return contador;
	}

	
	
	
	
	
	
	
	
	
	
	
	/**
	* ve o amigo de maior interesso para as trocas
	* @param Amigos Array 
	*/
	public void verAmigo(Caderneta2 amigo[]) {
		int maior = 0;
		boolean teste = false;
		int[] listaAmigos = verQuantidadeTrocas(amigo);

		for (int i = 1; i < listaAmigos.length; i++) {
			if (listaAmigos[i] > listaAmigos[maior]) {
				maior = i;
				teste = true;
			} else if (listaAmigos[i] < listaAmigos[maior]) {
				teste = true;
			}
		}
		if (teste) {
			System.out.println("Amigo: " + maior);
			System.out.println("recebi:");
		}
		efetuarTrocas(amigo[maior], this, listaAmigos[maior]);

		if (teste)
			System.out.println("dei:");
		efetuarTrocas(this, amigo[maior], listaAmigos[maior]);

	}

	
	
	
	/**
	* troca entre 2 amigos
	* @param cadernetaA
	* @param cadernetaB
	* @param nrTrocas 
	*/
	public void efetuarTrocas(Caderneta2 cadernetaA, Caderneta2 cadernetaB, int nrTrocas) {

		for (int k = 0; k < cadernetaA.cromo.length; k++) {

			if (cadernetaA.cromo[k].getQuant() == 0 && cadernetaB.cromo[k].getQuant() > 1 && nrTrocas > 0) {
				System.out.println("cromo:" + cadernetaA.cromo[k].getCromo());
				cadernetaA.cromo[k].setQuant(cadernetaA.cromo[k].getQuant() + 1);
				cadernetaB.cromo[k].setQuant(cadernetaB.cromo[k].getQuant() - 1);
				nrTrocas--;
			}
		}
	}
}