package Body;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class CsvReader extends ArrayList< ArrayList<String>> {
	/**
	 * A classe CsvReader é uma extensão da classe ArrayList e é usada para ler arquivos CSV.
	 * @version 1
	 * @author Rafael Rio
	 * @author Ricardo Fortuna
	 */
	
	private static final long serialVersionUID = 1L;

	/**
     * Construtor padrão da classe CsvReader.
     */
    public CsvReader() {
	}

    /**
     * Construtor da classe CsvReader que recebe o nome do arquivo e o delimitador.
     *
     * @param fileName  O nome do arquivo CSV a ser lido.
     * @param delimiter O delimitador usado para separar os campos no arquivo CSV.
     */
    public CsvReader(String fileName, String delimiter) {
    	Scanner scanner = null;
        try {
            scanner = new Scanner(new File(fileName));
            
            while (scanner.hasNextLine()) {
            	
                ArrayList<String> myList = new ArrayList<String>();
                String line = scanner.nextLine();
                StringTokenizer tokenizer = new StringTokenizer(line, delimiter);
               
                while (tokenizer.hasMoreTokens()) {
                    myList.add(tokenizer.nextToken());
                }
               
               add(myList);
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }finally {
        	scanner.close();
        }
    }
}

