
import static org.junit.Assert.assertEquals;

import org.junit.jupiter.api.Test;

class Caderneta2Test {

	@Test
	final void testCaderneta2() {

		Cromo2[] cromo = new Cromo2[2];
		cromo[0] = new Cromo2("QAT1", 1);
		cromo[1] = new Cromo2("QAT3", 1);

		Caderneta2 caderneta[] = new Caderneta2[2];
		caderneta[0] = new Caderneta2(cromo, 1);
		caderneta[1] = new Caderneta2(caderneta[0].getCromo(), caderneta[0].getID());

		assertEquals(cromo[0].cromoEquals(caderneta[0].cromo[0]), true);
		assertEquals(cromo[1].cromoEquals(caderneta[0].cromo[0]), false);
		assertEquals(caderneta[0].cadernetaEquals(caderneta[1]), true);
	}

	@Test
	final void testToString() {
		Cromo2 cromo1 = new Cromo2("QAT1", 1);
		assertEquals("toString cromo1", cromo1.toString(), "QAT1 1");
	}

	 @Test
	final void testVerQuantidadeTrocas() {

		  
		  int[] listaAmigos = new int[3];
				 int count1 = 3;
				 int count2 = 2;
				listaAmigos[0] = (count1 > count2) ? count2 : count1;
				
				 count1 = 4;
				 count2 = 3;
				listaAmigos[1] = (count1 > count2) ? count2 : count1;
				
				 count1 = 1;
				 count2 = 4;
				listaAmigos[2] = (count1 > count2) ? count2 : count1;
				
				assertEquals(2,listaAmigos[0]);
				assertEquals(3,listaAmigos[1]);
				assertEquals(1,listaAmigos[2]);	
	 }
	 
	@Test
	final void efetuarTrocas() {

		int nrTrocas = 2;

		Cromo2[] cromo0 = new Cromo2[2];
		cromo0[0] = new Cromo2("QAT1", 0);
		cromo0[1] = new Cromo2("QAT2", 0);

		Cromo2[] cromo1 = new Cromo2[2];
		cromo1[0] = new Cromo2("QAT1", 2);
		cromo1[1] = new Cromo2("QAT2", 2);

		Caderneta2[] amigo = new Caderneta2[3];
		amigo[0] = new Caderneta2(cromo0, 0);
		amigo[1] = new Caderneta2(cromo1, 1);

		for (int k = 0; k < amigo[0].cromo.length; k++) {

			if (amigo[0].cromo[k].getQuant() == 0 && amigo[1].cromo[k].getQuant() > 1 && nrTrocas > 0) {
				amigo[0].cromo[k].setQuant(amigo[0].cromo[k].getQuant() + 1);
				amigo[1].cromo[k].setQuant(amigo[1].cromo[k].getQuant() - 1);
				nrTrocas--;
			}
		}

		assertEquals(amigo[0].cromo[0].cromoEquals(amigo[1].cromo[0]), true);
		assertEquals(amigo[0].cromo[1].cromoEquals(amigo[1].cromo[1]), true);

	}
}
