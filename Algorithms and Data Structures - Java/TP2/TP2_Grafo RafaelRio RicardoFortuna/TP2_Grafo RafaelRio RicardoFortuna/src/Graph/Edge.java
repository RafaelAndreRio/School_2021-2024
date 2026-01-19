package Graph;

/**
 * A classe Edge representa uma aresta em um grafo.
 */

public class Edge {
	    private Node<String> from;
	    private Node<String> to;
	    private int value;

	    /**
	     * Construtor da classe Edge.
	     *
	     * @param from  O nó de origem da aresta.
	     * @param to    O nó de destino da aresta.
	     * @param value O valor associado à aresta.
	     */
	    public Edge(Node<String> from, Node<String> to, int value) {
	        this.from = from;
	        this.to = to;
	        this.value = value;
	    }
	    
	    /**
	     * Retorna o nó de origem da aresta.
	     *
	     * @return O nó de origem da aresta.
	     */
	    public Node<String> getFrom(){
	        return this.from;
	    }

	    /**
	     * Retorna o nó de destino da aresta.
	     *
	     * @return O nó de destino da aresta.
	     */
	    public Node<String> getTo(){
	        return this.to;
	    }

	    /**
	     * Retorna o valor associado à aresta.
	     *
	     * @return O valor associado à aresta.
	     */
	    public int getValue(){
	        return this.value;
	    }
}
