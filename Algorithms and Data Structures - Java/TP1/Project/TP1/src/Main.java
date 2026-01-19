/**
* class Main
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

public class Main {
	
	
	public static void main(String[] args) {
		/**
		*@param args um array de strings com os argumentos de entrada.
		*Primeiro argumento é o caminho do primeiro arquivo CSV,
		*Segundo argumento é o caminho do segundo arquivo CSV,
		*Terceiro argumento é o algoritmo a ser utilizado para o cálculo da similaridade.
		*Caso não sejam fornecidos argumentos, serão usados valores padrão.
		*@throws IllegalArgumentException se os parametros nao forem respeitados".
		*/
		
		String path1 = null, path2 = null;
		String algoritmo_usado = null;


		// valida e carrega do args
		if (args.length == 3) {
			path1 = args[0];
			path2 = args[1];
			algoritmo_usado = args[2];
		} else {
			if(algoritmo_usado==null && args.length<=3) {
			path1="D:\\Work Spasce\\Eclipse\\TP1\\dataset_1.CSV";
			path2="D:\\Work Spasce\\Eclipse\\TP1\\dataset_2.CSV";
			//algoritmo_usado="jaccard";
			//algoritmo_usado="levenshtein";
			//algoritmo_usado="coisine";
			algoritmo_usado="hamming";

			}
			else
				throw new IllegalArgumentException("Erro nos Argumentos de entrada");
		}

		OutPut.mostrar(path1, path2, algoritmo_usado);
	}
}
