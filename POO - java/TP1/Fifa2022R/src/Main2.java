/**
* class Main2
* @version 1
* @author Ricardo Fortuna
* @author Rafael Rio
* @return Avaliação
*/

import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

public class Main2 {

	public static void main(String[] args) {
		Scanner sc = null;
		Caderneta2 user = new Caderneta2(null, 0);
		Caderneta2[] amigo = null;
		boolean completou = false;

		try {
			sc = new Scanner(new File("input1.txt"));
			user.cromo = new Cromo2[sc.nextInt()]; // Ler quantidade cromos do user
			for (int k = 0; k < user.cromo.length; k++) {
				user.cromo[k] = new Cromo2(sc.next(), sc.nextInt()); // Ler cromo a cromo
			}	
			
			amigo = new Caderneta2[sc.nextInt()]; // Ler quantidade de amigos

			for (int i = 0; i < amigo.length; i++) {
				amigo[i] = new Caderneta2(null, i + 1);
				amigo[i].cromo = new Cromo2[sc.nextInt()];
				for (int k = 0; k < amigo[i].cromo.length; k++) {
					amigo[i].cromo[k] = new Cromo2(sc.next(), sc.nextInt());
				}
			}

			
				//Confirmar se a minha caderneta está completa
			for (int i = 0; i < user.cromo.length; i++) {

				if (amigo[0].cromo[i].getQuant() != 0) {	//boolean para nao aparecer o que falta vazio.
					completou = true;
				}
			}
			if (!completou) {
				System.out.println("falta o(s) Cromo(s)");

				for (int i = 0; i < user.cromo.length; i++) {
					if (amigo[0].cromo[i].getQuant() == 0) {
						System.out.println(amigo[0].cromo[i].getCromo());
					}

				}
			}

			for (int i = 0; i < amigo.length; i++) {
				user.verAmigo(amigo);
			}
				
				
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}

			
			
			finally {
				sc.close();
			}
	}
}
