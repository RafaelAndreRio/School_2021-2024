
/**
* class OutPut
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

import java.util.ArrayList;

public class OutPut {
	/**
	 * exibe os resultados da comparação em formato tabular.
	 * 
	 * @param path1           O caminho do primeiro arquivo CSV.
	 * @param path2           O caminho do segundo arquivo CSV.
	 * @param algoritmo_usado O algoritmo usado para calcular o índice de
	 *                        similaridade entre os dados.
	 */
	public static ArrayList<ArrayList<String>> mostrar(String path1, String path2, String algoritmo_usado) {

		double suportIScore = 0;
		double suportToSaveList = 0;
		String suportkey = null;
		int i = 0; // Indices Suport dos ForEachs HashMaps

		// Carrega os files CSV
		CsvReader file1 = new CsvReader(path1);
		CsvReader file2 = new CsvReader(path2);

		// construção de lista de hash
		ArrayList<CsvReader> myList = new ArrayList<CsvReader>();
		myList.add(file1);
		myList.add(file2);

		// Declarar board para imprimir no final
		ArrayList<ArrayList<String>> board = new ArrayList<ArrayList<String>>();

		// Mostra e Guarda na Lista Board os results
		for (String key1 : myList.get(0).keySet()) {
			ArrayList<String> arraySuport = new ArrayList<String>();
			suportIScore = 0;
			suportToSaveList = 0;
			if (algoritmo_usado.equals("coisine")) 
				suportToSaveList = 100;
			
			for (String key2 : myList.get(1).keySet()) {

				// Guarda o valor da comparação do metodo dentro da variavel,
				suportIScore = IScore.calculateScore(key1, key2, algoritmo_usado);

				// System.out.println(key1 + " " + key2 + " " + suportIScore);
				if (algoritmo_usado.equals("coisine")) {
					if (suportIScore < suportToSaveList ) {
						suportToSaveList = suportIScore;
						suportkey = key2;
					}
				} else {
					if (suportIScore >= suportToSaveList) {
						suportToSaveList = suportIScore;
						suportkey = key2;
					}
				}
			}

			// Criar ArrayList de suporte para injetar na board´

			arraySuport.add(key1);
			arraySuport.add(suportkey);
			arraySuport.add(Double.toString(suportToSaveList)); // converte o index de double para String
			board.add(i, arraySuport);
			i++;
		}

		// inserir Data1 no ArrayList
		i = 0;
		for (String valor : myList.get(0).values()) {
			board.get(i).add(valor);
			i++;
		}

		// inserir Data2 no ArrayList
		i = 0;
		for (String valor : myList.get(1).values()) {
			board.get(i).add(valor);
			i++;
		}

		// Print
		System.out.printf("%-25s \t %-25s \t %-25s \t %-25s \t\n", board.get(0).get(0), board.get(0).get(3),
				board.get(0).get(4), algoritmo_usado);

		for (i = 1; i < board.size(); i++) {
			System.out.printf("%-25s \t %-25s \t %-25s \t %-25.5s \t", board.get(i).get(0), board.get(i).get(3),
					board.get(i).get(4), board.get(i).get(2));
			System.out.println();
		}

		return board;
	}
}
