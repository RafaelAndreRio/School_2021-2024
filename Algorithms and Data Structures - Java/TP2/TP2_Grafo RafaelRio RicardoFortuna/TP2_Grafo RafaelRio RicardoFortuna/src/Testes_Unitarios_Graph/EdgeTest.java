package Testes_Unitarios_Graph;

import Graph.*;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class EdgeTest {

	@Test
	void testEdge() {
		
		Edge graph = new Edge(new Node<String>("algoritmo"),new Node<String>("extrutura"), 20);
		
		assertEquals(graph.getFrom().getValue() , "algoritmo");
		assertEquals(graph.getTo().getValue() , "extrutura");
		assertEquals(graph.getValue() , 20);
		
	}

}
