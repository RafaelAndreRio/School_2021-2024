import java.util.*;

/**
* class IScore
* @version 1
* @author Rafael Rio
* @author Ricardo Fortuna
*/

public class IScore {

	/**
	 * @param s1 a primeira string a ser comparada.
	 * @param s2 a segunda string a ser comparada.
	 * @param o método a ser usado para calcular a pontuação de semelhança.
	 * @return a pontuação de semelhança calculada usando o método especificado.
	 * @throws IllegalArgumentException se o método especificado não estiver na lista de algoritmos
	 */
	public static double calculateScore(String s1, String s2, String metodo) {
		switch (metodo) {
		case "jaccard":
			return jaccard(s1, s2);
		case "levenshtein":
			return (s1.length() + s2.length() - (levenshtein(s1, s2))) / (s1.length() + s2.length());
		case "hamming":
		return hamming(s1, s2);
		case "coisine":
			return (s1.length() + s2.length() - (coisine(s1, s2))) / (s1.length() + s2.length());
		default:
			throw new IllegalArgumentException("Método inválido: " + metodo);
		}
	}

	/**
	 * Calcula a pontuação de semelhança entre duas strings usando o método de
	 * Jaccard.
	 * 
	 * @param s1 a primeira string a ser comparada.
	 * @param s2 a segunda string a ser comparada.
	 * @return double calculo usando o método de Jaccard.
	 */

	// Método de Jaccard
	private static double jaccard(String s1, String s2) {
		// Implementação do método de Jaccard
		// Converter as strings em conjuntos de caracteres
		HashSet<Character> set1 = new HashSet<>();
		HashSet<Character> set2 = new HashSet<>();
		double jaccardIndex = 0.0;
		double intersectionSize;
		double unionSize;

		for (int i = 0; i < s1.length(); i++) {set1.add(s1.charAt(i));}
		for (int i = 0; i < s2.length(); i++) {set2.add(s2.charAt(i));}
		
		// Calcular o tamanho da interseção dos conjuntos de caracteres
		HashSet<Character> intersection = new HashSet<>(set1);
		intersection.retainAll(set2);
		intersectionSize = intersection.size();
		// Calcular o tamanho da união dos conjuntos de caracteres
		HashSet<Character> union = new HashSet<>(set1);
		union.addAll(set2);
		unionSize = union.size();
		// Calcular o índice de Jaccard
		if (unionSize > 0) { jaccardIndex = (intersectionSize / unionSize);}
		return jaccardIndex;
	}

	/**
	 *Calcula a pontuação de semelhança entre duas strings usando o método de Levenshtein.
	 *@param s1 a primeira string a ser comparada.
	 *@param s2 a segunda string a ser comparada.
	 *@return int calculo usando o método de Levenshtein.
	 */
	// Método de Levenshtein
	private static double levenshtein(String s1, String s2) {
		// Implementação do método de Levenshtein
		// Cria uma matriz com tamanho s1.length() + 1 por s2.length() + 1
		double[][] matrix = new double[s1.length() + 1][s2.length() + 1];
		double result = 0;
		// Inicializa a primeira linha e a primeira coluna da matriz com números
		// inteiros consecutivos
		for (int i = 0; i <= s1.length(); i++) {matrix[i][0] = i;}
		for (int j = 0; j <= s2.length(); j++) {matrix[0][j] = j;}
		// Preenche a matriz com os valores mínimos
		for (int i = 1; i <= s1.length(); i++) {
			for (int j = 1; j <= s2.length(); j++) {
				int cost = (s1.charAt(i - 1) == s2.charAt(j - 1)) ? 0 : 1;
				matrix[i][j] = Math.min(Math.min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1),
						matrix[i - 1][j - 1] + cost);
			}
		}
		result = (matrix[s1.length()][s2.length()]);
		return result;
	}

	/**
	 * Distância de Hamming entre duas strings.
	 * @param s1 a primeira string
	 * @param s2 a segunda string
	 * @return a distância de Hamming entre as duas strings, ou 0 se as strings tiverem tamanhos diferentes
	 */
	public static double hamming(String s1, String s2) {
		double diferenca = 0;
		
		if (s1.length() == s2.length()) {
			for (int i = 0; i < s1.length(); i++) { 
													
				if (s1.charAt(i) != s2.charAt(i)) {
					diferenca++; // Incrementa a distância se os caracteres são diferentes
				}
			}
			return diferenca;
		}
		return diferenca;
		
	}
	
	/**
	 * Similaridade cosseno entre duas strings.
	 * @param s1 a primeira string
	 * @param s2 a segunda string
	 * @return a similaridade cosseno entre as duas strings, representada como um valor double
	 */
	
	public static double coisine(String s1, String s2) {
        // Pré-processamento dos textos
        String[] palavra1 = s1.toLowerCase().split("\\s+");
        String[] palavra2 = s2.toLowerCase().split("\\s+");
        
        // Construção dos vetores de frequência das palavras
        Map<String, Integer> Freq_palavra1 = new HashMap<>();
        Map<String, Integer> Freq_palavra2 = new HashMap<>();
        
        for (String word : palavra1) {
            Freq_palavra1.put(word, Freq_palavra1.getOrDefault(word, 0) + 1);
        }
        
        for (String word : palavra2) {
            Freq_palavra2.put(word, Freq_palavra2.getOrDefault(word, 0) + 1);
        }
        
        // Cálculo do produto interno dos vetores de frequência
        double dotProduct = 0.0;
        for (String word : Freq_palavra1.keySet()) {
            if (Freq_palavra2.containsKey(word)) {
                dotProduct += Freq_palavra1.get(word) * Freq_palavra2.get(word);
            }
        }

        // Cálculo das normas dos vetores de frequência
        double norm1 = calculateNorm(Freq_palavra1);
        double norm2 = calculateNorm(Freq_palavra2);
        
        // Cálculo da similaridade cosseno
        double cosineSimilarity = (dotProduct / (norm1 * norm2));

        return cosineSimilarity;
    }
    
	/**
	 * Calcula a norma de um vetor de frequência.
	 * @param wordFreq o vetor de frequência representado como um mapa de palavras e suas frequências
	 * @return a norma do vetor de frequência, representada como um valor double
	 */
    private static double calculateNorm(Map<String, Integer> wordFreq) {
        double norm = 0.0;
        for (double freq : wordFreq.values()) {
            norm += Math.pow(freq, 2);
        }
        return Math.sqrt(norm);
    }
	
}
