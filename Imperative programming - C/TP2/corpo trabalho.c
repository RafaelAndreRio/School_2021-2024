// Disciplina: Programação Imperativa
// Autor: Rafael Rio
// Main: Rotina Entrada
// Livraria: Rotina Entrada
// Descrição: Uso de Rotinas Base para desafio2
// Data 22/04/2022


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "RotinaChars.h"    //biblioteca pessoal

int menu(){         //apresentaçao de menu, e opção
    int opcao;
    do{
    lcaract(80,'*');
    lcaract(1,10);
        printf("  Menu Rotina de dados:\n");
    lcaract(1,10);
        printf("\t\tTipo 1 - Letras Maiúsculas\n");
        printf("\t\tTipo 2 - Letras minúsculas\n");
        printf("\t\tTipo 3 - Letras Maiúsculas + Caracteres especiais\n");
        printf("\t\tTipo 4 - Letras miniúsculas + Caracteres especiais\n");
        printf("\t\tTipo 5 – Números inteiros\n");
        printf("\t\tTipo 6 – Números decimais\n");
        printf("\t\tTipo 7 – Letras maiúsculas, minúsculas e números\n");
        printf("\t\tTipo 8 – Todos os caracteres\n");
    lcaract(80,'*');
    lcaract(2,10);
        printf("Escolha a opção que pretende\nTipo:");
        scanf("%i", &opcao);
    clean();
    }while(opcao>8 || opcao<1);

    return opcao;
}

int comprimento(int opcao){ //pedir ao utilizador os tamanhos consoante a opção de escolha
    int tamanho=0;
    clean();
        if (opcao==5)
            printf("A quantidade de numeros que o seu numero contem?\n");
        else if (opcao==6)
            printf("A quantidade de numeros que o seu numero contem apos a virgula?\n");
        else{
            printf("A quantidade de caracteres que pretente escrever?\n");
        }
        scanf("%i", &tamanho);
    clean();
    return tamanho;
}

    void main() {
        setlocale(LC_ALL, "Portuguese");

    int opcao=0,tamanho=0,deci=0;
    char *nome;

    opcao=menu();
    tamanho = comprimento(opcao);

    RotinaDados(opcao,tamanho,deci,nome);

    }
