package Body;

import java.util.*;

/**
 * A classe Input é responsável por processar os argumentos de entrada e carregar os dados necessários para o processamento.
 * @version 1
 * @author Rafael Rio
 * @author Ricardo Fortuna
 */
public class Input {
	
	// argumentos do Args do "main"
	private String correlation = null;
	private String time = null;
	private int minSizeString = 0;

	// Variaveis necessarias para o processamento
	private CsvReader fileTime;
	private CsvReader fileCorrelation;
	private String[] header;
	private int[][] matrizAdjacência;
	ArrayList<String> ordemLeitura = new ArrayList<String>();
	Process process;

    /**
     * Construtor da classe Input que valida e carrega os argumentos de entrada.
     * Se os argumentos não estiverem na ordem esperada, ele corrige e atribui aos lugares certos.
     *
     * @param args Os argumentos de entrada fornecidos ao programa.
     */
	public Input(String[] args) {
		if (args.length == 3) {
			for (int i = 0; i < args.length; i++) {

				String stringDivide[] = args[i].split("=");

				if (stringDivide[0].equals("correlation")) {
					this.correlation = stringDivide[1];
				} else if (stringDivide[0].equals("time")) {
					this.time = stringDivide[1];
				} else if (stringDivide[0].equals("threshold")) {
					this.minSizeString = Integer.parseInt(stringDivide[1]);
				} else
					throw new IllegalArgumentException("Erro nos Argumentos de entrada");
			}
		}
		
		
		else { // Testes para o programador
			if (this.time == null && args.length != 3) {
				this.correlation = ".\\correl.CSV";
				this.time = ".\\time.CSV";
				this.minSizeString = Integer.parseInt("80");
			}

			// Construçao dos objectos
			fileCorrelation = new CsvReader(this.correlation, ",");
			fileTime = new CsvReader(this.time, ",");

			header = new String[fileCorrelation.get(0).size()];
			matrizAdjacência = new int[fileCorrelation.get(0).size() - 1][fileCorrelation.get(0).size() - 1];

			// construçao dos nós
			for (int i = 0; i < fileCorrelation.get(0).size(); i++) {
				this.header[i] = new String(fileCorrelation.get(0).get(i));
			}

			// contrução do corpo da matrizAdjacência
			for (int i = 1; i < fileCorrelation.size(); i++) {
				for (int x = 1; x < fileCorrelation.size(); x++) {
					if (Integer.parseInt(fileCorrelation.get(i).get(x)) < minSizeString) {
						matrizAdjacência[i - 1][x - 1] = -1;
					} else {
						matrizAdjacência[i - 1][x - 1] = Integer.parseInt(fileCorrelation.get(i).get(x));
					}
				}
			}

			// contrução da ordem de entrega
			for (int i = 1; i < fileTime.size(); i++) {
				String linha = fileTime.get(i).toString();
				String stringDivide[] = linha.split(",");
				ordemLeitura.add(stringDivide[0].substring(1));
			}

			process = new Process(ordemLeitura, header, matrizAdjacência, minSizeString);
		}
	}
	
	/**
	 * Retorna o valor do atributo correlation.
	 *
	 * @return O valor do atributo correlation.
	 */
	public String getCorrelation() {
		return correlation;
	}
	
	/**
	 * Retorna o valor do atributo time.
	 *
	 * @return O valor do atributo time.
	 */
	public String getTime() {
		return time;
	}
	
	/** Retorna o valor do atributo minSizeString.
	 *
	 * @return O valor do atributo minSizeString.
	 */
	public int getMinSizeString() {
		return minSizeString;
	}
	
}
