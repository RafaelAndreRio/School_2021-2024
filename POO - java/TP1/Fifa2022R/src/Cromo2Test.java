import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.jupiter.api.Test;

class Cromo2Test {

	@Test
	final void testCromo2() {

		Cromo2 cromo1 = new Cromo2("QAT1", 1);
		Cromo2 cromo2 = new Cromo2("ECU1", 2);
		assertEquals("toString cromo1" , cromo1.toString(), "QAT1 1");
		assertEquals("ToString cromo2" , cromo2.toString(), "ECU1 2");
		assertEquals("Assert cromo", cromo1.getCromo(), "QAT1");
		assertEquals("Assert Quant", cromo1.getQuant(), 1);
	}

	@Test
	final void testGetCromo() {
		Cromo2 cromo1 = new Cromo2("QAT1", 1);
		Cromo2 cromo2 = new Cromo2("ECU1", 2);
		assertEquals("Assert get Cromo" , cromo1.getCromo(), "QAT1");
		assertEquals("Assert get Cromo" , cromo2.getCromo(), "ECU1");
	}

	@Test
	final void testGetQuant() {
		Cromo2 cromo1 = new Cromo2("QAT1", 1);
		Cromo2 cromo2 = new Cromo2("ECU1", 2);
		assertEquals("Assert get quant", cromo1.getQuant(), 1);
		assertEquals("Assert get quant", cromo2.getQuant(), 2);
	}
	
	
	@Test
	final void cromoEquals() {

		boolean check= false;
		
		Cromo2 cromo1 = new Cromo2("ECU1", 2);
		Cromo2 cromo2 = new Cromo2("ECU1", 2);
		
		if(cromo1.getCromo()==cromo2.getCromo() && cromo1.getQuant()==cromo2.getQuant()) {
			check=true;
			assertTrue(cromo1.getCromo()==cromo2.getCromo() && cromo1.getQuant()==cromo2.getQuant());
			assertEquals(true, cromo1.getCromo()==cromo2.getCromo() && cromo1.getQuant()==cromo2.getQuant());

		}
		assertTrue(check);

		//assertEquals
	}


}
