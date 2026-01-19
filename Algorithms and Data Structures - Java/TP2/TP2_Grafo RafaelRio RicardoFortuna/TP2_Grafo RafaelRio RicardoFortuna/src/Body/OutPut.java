package Body;
import java.util.ArrayList;
import Graph.Graph;
/**
 * A classe OutPut é responsável por imprimir os resultados do processamento, incluindo os grupos calculados e a matriz de adjacência.
 * @version 1
 * @author Rafael Rio
 * @author Ricardo Fortuna
 */
public class OutPut {
	/**
     * Construtor da classe OutPut que recebe o grafo, a ordem de leitura, o cabeçalho e a matriz de adjacência.
     *
     * @param grafo             O grafo a ser processado.
     * @param ordemLeitura      A lista de ordem de leitura.
     * @param header            O array de cabeçalho.
     * @param matrizAdjacência  A matriz de adjacência.
     */
	public OutPut(Graph grafo, ArrayList<String> ordemLeitura,String[] header, int matrizAdjacência[][]) {
	
	ArrayList<ArrayList<Object>> dataBuild = new ArrayList<ArrayList<Object>>();

	dataBuild=grafo.CalculoGrupos(ordemLeitura);
	
	for(int i=0; i< dataBuild.size() ; i++) {
		System.out.println("vertice : " + dataBuild.get(i).get(0));

		for(int x=1 ; x < dataBuild.get(i).size() ; x++){			
			if(dataBuild.get(i).get(x)instanceof Double) {
				System.out.printf("(%.2f%%)\n", dataBuild.get(i).get(x));
			System.out.println();
			}else
			System.out.print(dataBuild.get(i).get(x));
		}
	}
	//impressao da matriz
	printMatrizAdjacência(header, matrizAdjacência);
	}
	
    /**
     * Imprime a matriz de adjacência.
     *
     * @param header            O array de cabeçalho.
     * @param matrizAdjacência  A matriz de adjacência.
     */
	public void printMatrizAdjacência(String[] header, int matrizAdjacência[][]) {

		for (int i = 0; i < header.length; i++) {
			System.out.printf("%5s |", header[i]);
		}

		for (int i = 0; i < matrizAdjacência.length; i++) {
			System.out.printf("\n%5s |", header[i + 1]);
			for (int x = 0; x < matrizAdjacência.length; x++) {
				System.out.printf("%5d |", matrizAdjacência[i][x]);
			}
		}
	}
	
}
