package Testes_Unitarios_Main;

import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import Body.CsvReader;
import Body.Input;

class InputTest {

    private Input input;
	
    
    @BeforeEach
    void setUp() {
        // Configurar os argumentos de teste
        String[] args = {"correlation=correlation.csv", "time=time.csv", "threshold=80"};
        input = new Input(args);
    }
    
    @Test
    void testInputWithValidArgs() {
        // Verificar se os argumentos foram carregados corretamente
        assertEquals("correlation.csv", input.getCorrelation());
        assertEquals("time.csv", input.getTime());
        assertEquals(80, input.getMinSizeString());
    }
    
    @Test
    void testInputForProgrammer() {
        // Configurar argumentos vazios
        String[] args = {};

        // Criar uma instância de Input com argumentos vazios
        input = new Input(args);

        // Verificar se os valores padrão para o programador são aplicados corretamente
        assertEquals(".\\correl.CSV", input.getCorrelation());
        assertEquals(".\\time.CSV", input.getTime());
        assertEquals(80, input.getMinSizeString());
    }

    
	@Test
	void Input() {

		String[] args = new String[] {"correlation=\\correl.csv","time=\\time.csv",
				"threshold=80" };

		// argumentos do Args do "main"
		String correlation = null;
		String time = null;
		int minSizeString = 0;
		
		ArrayList<String> suport = new ArrayList<String>();
		ArrayList<String> suport1 = new ArrayList<String>();
		ArrayList<String> suport2 = new ArrayList<String>();
		ArrayList<String> suport3 = new ArrayList<String>();
		ArrayList<String> suportTime = new ArrayList<String>();


		// Variaveis necessarias para o processamento
		CsvReader fileTime;
		CsvReader fileCorrelation=new CsvReader();
		String[] header;
		int[][] matrizAdjacência;

		ArrayList<String> ordemLeitura = new ArrayList<String>();

		// valida e carrega do args do main
		// Se nao for posto pela suposta ordem de Input, ele corrige para os sitios
		// certos
		int contadorTeste=args.length;
		
		for (int i = 0; i < args.length; i++) {

			String stringDivide[] = args[i].split("=");

			if (stringDivide[0].equals("correlation")) {
				correlation = stringDivide[1];
			} else if (stringDivide[0].equals("time")) {
				time = stringDivide[1];
			} else{
				minSizeString = Integer.parseInt(stringDivide[1]);
			}
			contadorTeste--;
		}
		assertEquals(contadorTeste,0);
			assertEquals(correlation, "\\correl.csv");
			assertEquals(time, "\\time.csv");
			assertEquals(minSizeString, 80);

			// Construçao dos objectos
			suport.add("row");
			suport.add("S1");
			suport.add("S2");
			suport.add("S3");
				fileCorrelation.add(suport);
			suport1.add("S1");
			suport1.add("100");
			suport1.add("90");
			suport1.add("50");
				fileCorrelation.add(suport1);
			suport2.add("S2");
			suport2.add("90");
			suport2.add("100");
			suport2.add("50");
				fileCorrelation.add(suport2);
			suport3.add("S3");
			suport3.add("50");
			suport3.add("50");
			suport3.add("100");
				fileCorrelation.add(suport3);
				
			fileTime = new CsvReader();
			suportTime.add("S1");
					fileTime.add(suportTime);
					
			suportTime.add("S2");
					fileTime.add(suportTime);
					
			suportTime.add("S2");
					fileTime.add(suportTime);
				
			header = new String[fileCorrelation.get(0).size()];
			matrizAdjacência = new int[fileCorrelation.get(0).size() - 1][fileCorrelation.get(0).size() - 1];

			// construçao dos nós
			for (int i = 0; i < fileCorrelation.get(0).size(); i++) {
				header[i] = new String(fileCorrelation.get(0).get(i));
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

		}
}
