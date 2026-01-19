package Graph;


/**
 * A classe Node representa um nó em um grafo.
 * @param <T> O tipo de valor armazenado no nó.
 */

public class Node <T>{
    private T value;
   
    /**
     * Construtor da classe Node.
     * @param value O valor a ser armazenado no nó.
     */
    public Node(T value) {
        this.value = value;
    }

    /**
     * Retorna o valor armazenado no nó.
     * @return O valor armazenado no nó.
     */
    public T getValue(){
        return this.value;
    }
}
