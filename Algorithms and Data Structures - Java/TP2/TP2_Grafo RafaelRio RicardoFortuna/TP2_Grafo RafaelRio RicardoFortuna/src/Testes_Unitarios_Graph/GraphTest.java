package Testes_Unitarios_Graph;

import static org.junit.Assert.assertEquals;

import java.util.ArrayList;

import org.junit.jupiter.api.Test;

import Graph.Edge;
import Graph.Graph;
import Graph.Node;

class GraphTest extends ArrayList<Edge> {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Test
	void CalculoGrupos() {

		Graph grafo = new Graph();
		
		ArrayList<ArrayList<Object>> grupoMain = new ArrayList<ArrayList<Object>>();

		Edge edge = new Edge(new Node<String>("S1"), new Node<String>("S1"), 100);
		grafo.add(edge);
		Edge edge1 = new Edge(new Node<String>("S2"), new Node<String>("S3"), 100);
		grafo.add(edge1);
		Edge edge2 = new Edge(new Node<String>("S3"), new Node<String>("S3"), 100);
		grafo.add(edge2);
		Edge edge4 = new Edge(new Node<String>("S1"), new Node<String>("S2"), 90);
		grafo.add(edge4);
		Edge edge5 = new Edge(new Node<String>("S2"), new Node<String>("S3"), -1);
		grafo.add(edge5);

		ArrayList<String> ordemLeitura = new ArrayList<String>();
		ordemLeitura.add("S1");
		ordemLeitura.add("S2");
		ordemLeitura.add("S3");

		double mediaTeste1 = ((100 + 90) / 2);
		double mediaTeste2 = 100;

		int contadorTeste=ordemLeitura.size();
		
		while (ordemLeitura.size() > 0) {
			ArrayList<Object> grupoData = new ArrayList<>();
			double media = 0;
			int size = 0;
			
			String grupoComparado = ordemLeitura.get(0).toString();
			grupoData.add(ordemLeitura.get(0).toString());

			for (int x = 0; x < grafo.size(); x++) {

				if ((grupoComparado.compareTo((grafo.get(x).getFrom().getValue())) == 0)) {
					grupoData.add(grafo.get(x).getTo().getValue() + ", ");

					media += grafo.get(x).getValue();
					size++;

					ordemLeitura.remove((grafo.get(x).getTo().getValue()));
					contadorTeste--;
				}
				assertEquals(ordemLeitura.size(),contadorTeste);
			}

			grupoData.add((double) (media / size));
			grupoMain.add(grupoData);
		}
		assertEquals(grupoMain.get(0).get(0),"S1");
		assertEquals(grupoMain.get(0).get(1),"S1"+", ");
		assertEquals(grupoMain.get(0).get(2),"S2"+", ");
		assertEquals(grupoMain.get(0).get(3),mediaTeste1);
		
		assertEquals(grupoMain.get(1).get(0),"S3");
		assertEquals(grupoMain.get(1).get(1),"S3"+", ");
		assertEquals(grupoMain.get(1).get(2),mediaTeste2);
	}
}