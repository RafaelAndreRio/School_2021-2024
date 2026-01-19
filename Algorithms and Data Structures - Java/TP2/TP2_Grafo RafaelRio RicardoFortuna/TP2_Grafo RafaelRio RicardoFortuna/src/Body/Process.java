package Body;
import Graph.*;
import java.util.*;
/**
 * A classe Process é responsável por processar os dados e construir o grafo com base nas informações fornecidas.
 * @version 1
 * @author Rafael Rio
 * @author Ricardo Fortuna
 */
public class Process {
	private Graph grafo= new Graph();
	OutPut outPut;
	
	 /**
     * Construtor da classe Process que recebe os dados necessários para a construção do grafo.
     *
     * @param ordemLeitura      A lista de ordem de leitura.
     * @param header            O array de cabeçalho.
     * @param matrizAdjacência  A matriz de adjacência.
     * @param minSizeString     O tamanho mínimo de string.
     */
	public Process( ArrayList<String> ordemLeitura, String[] header, int matrizAdjacência[][], int minSizeString) {
		
		//Construção do grafo
		for(int i=0 ; i < header.length-1  ; i++) {
			for(int x=0 ; x < header.length-1  ; x++) {
				if( matrizAdjacência[i][x]>minSizeString ) {
					Edge edge=new Edge(new Node<String>(header[i+1]), new Node<String>(header[x+1]) , matrizAdjacência[i][x] );
				grafo.add(edge);
				}
			}
		}
		outPut = new OutPut(grafo, ordemLeitura, header, matrizAdjacência);		
	}}

