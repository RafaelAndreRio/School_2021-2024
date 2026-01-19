package Graph;

import java.util.ArrayList;
/**
 * A classe Graph representa um grafo que é uma lista de arestas.
 */
public class Graph extends ArrayList<Edge> {

	
	ArrayList<ArrayList<Object>> grupoMain = new ArrayList<ArrayList<Object>>();

    /**
     * Serial Version UID para a serialização da classe.
     */
	private static final long serialVersionUID = 1L;

	 /**
     * Calcula os grupos com base na ordem de leitura fornecida.
     *
     * @param ordemLeitura A ordem de leitura dos nós.
     * @return Uma lista de grupos, onde cada grupo é representado por uma lista de objetos.
     */
	public ArrayList<ArrayList<Object>> CalculoGrupos(ArrayList<String> ordemLeitura) {

		while (ordemLeitura.size() > 0) {
			ArrayList<Object> grupoData = new ArrayList<>();
			double media = 0;
			int size = 0;

			String grupoComparado = ordemLeitura.get(0).toString();
			grupoData.add(ordemLeitura.get(0).toString());

			for (int x = 0; x < this.size(); x++) {

				if ((grupoComparado.compareTo((this.get(x).getFrom().getValue())) == 0)) {
					grupoData.add(this.get(x).getTo().getValue() + ", ");

					media += this.get(x).getValue();
					size++;

					ordemLeitura.remove((this.get(x).getTo().getValue()));
				}
			}
			
			grupoData.add((double)(media / size));
			grupoMain.add(grupoData);
		}

		return grupoMain;
	}
}