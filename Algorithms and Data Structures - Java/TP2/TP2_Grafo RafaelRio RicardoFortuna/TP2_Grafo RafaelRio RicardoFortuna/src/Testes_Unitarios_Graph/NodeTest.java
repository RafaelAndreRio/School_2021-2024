package Testes_Unitarios_Graph;

import Graph.Node;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class NodeTest {

	@Test
	void testNode() {
	Node<String> name = new Node<String> ("Algoritmo");
	assertEquals(name.getValue() ,"Algoritmo");
	}

}
