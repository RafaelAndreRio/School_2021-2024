// Disciplina: Programação Imperativa
// Autor: Rafael Rio
// Main: Rotina Entrada
// Livraria: Rotina Entrada
// Descrição: Uso de Rotinas Base para desafio2
// Data 22/04/2022

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#include <string.h>

void clean(){        //Rotina limpa ecrâ
    system("cls");
    }

void lcaract(int nColunas, char car){       //repete caracteres         (10) = \n
    int i;
        for(i=0;i<nColunas;i++)     printf("%c",car);
}

void RotinaDados(int tipo, int tamanho, int deci, unsigned char *nome){

    setlocale(LC_ALL, "Portuguese");

    unsigned char entrada=NULL;         //unsigned para o ascii ser 0 ate 255
    int i=0;

    nome=(char *)malloc(tamanho);           //criação do array com alocagem
    printf("Introduza os caracteres.\n");
    do{
            entrada=getche();
            if(entrada==224){           //previne a entrada de: "setas de direção, Del"
                    entrada=getch();
                    entrada=0;
            }

        switch (tipo){
            case 1:{    //Tipo 1 - Letras Maiúsculas [65,90]+{32}


                if( entrada>64 && entrada<91 || (entrada==32)){
                    nome[i]=entrada;
                    nome[i+1]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                    i++;
                }
                else if (entrada == 13){ //Tecla enter
                    i=tamanho;
                }
                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                }
                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o nome:%s", nome);
                }
            break;}

            case 2:{    //Tipo 2 - Letras minúsculas [95,122]+{32}

                if(entrada > 96 && entrada < 123 || entrada==32){
                    nome[i]=entrada;
                    nome[i+1]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                    i++;
                }
                else if (entrada == 13){ //Tecla enter

                    i=tamanho;
                }
                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                }
                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o nome:%s", nome);
                }
            break;}

            case 3:{   //Tipo 3 - Letras Maiúsculas [65,90]+{32} + Caracteres especiais: &,$,+,* …

                if(entrada > 64 && entrada < 91 ||entrada>31 && entrada<48 || entrada>57 && entrada<65 || entrada>90 && entrada< 97 || entrada>122 && entrada<127){
                    nome[i]=entrada;
                    nome[i+1]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                    i++;
                }

                else if (entrada == 13){ //Tecla enter
                    i=tamanho;
                }
                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                }
                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o nome:%s", nome);
                }
            break;}

            case 4:{    //Tipo 4 - Letras miniúsculas + Caracteres especiais: &,$,+,* …

                if(entrada > 96 && entrada < 128 ||entrada>31 && entrada<48 || entrada>57 && entrada<65 || entrada>90 && entrada< 97 || entrada>122 && entrada<127){
                    nome[i]=entrada;
                    nome[i+1]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                    i++;
                }
                else if (entrada == 13){ //Tecla enter

                    i=tamanho;
                }
                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                }
                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o nome:%s", nome);
                }
            break;}

            case 5:{    //Tipo 5 – Números inteiros [48,56]

                if(entrada > 47 && entrada<57){ //Números inteiros [48,56]
                    nome[i]=entrada;
                    nome[i+1]=NULL;
                    clean();
                    printf("Entre com o numero:%s", nome);
                    i++;
                }

                else if (entrada == 13){ //Tecla enter

                    i=tamanho;
                }

                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o numero:%s", nome);
                }

                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o numero:%s", nome);
                }

            break;}

            case 6:{    //Tipo 6 – Números decimais

                if(entrada > 47 && entrada < 58 || entrada==46){ //Números inteiros [48,56]
                        if(entrada==46){            //se for '.' entra.
                                if(deci==1){       //se a flag deci for 1, nao deixa escrever outro ponto.
                                    nome[i]=NULL;
                                    clean();
                                    printf("Entre com o numero:%s", nome);
                                    break;
                                    }
                                else {
                                    deci=1;
                                    tamanho++;
                                }
                        }

                        // So temos a quantidade de casas decimais vindas do main.
                        //antes de o utilizador por um '.' existe uma reallocagem de memoria constante

                        if(deci==1){
                        nome[i]=entrada;
                        nome[i+1]=NULL;
                        clean();
                        printf("Entre com o numero:%s", nome);
                        i++;
                        }
                        else{
                            tamanho++;
                            nome=realloc(nome,tamanho*sizeof(char));        //re-locagem constante
                            nome[i]=entrada;
                            nome[i+1]=NULL;
                            clean();
                            printf("Entre com o numero:%s", nome);
                            i++;
                            }
                        }

                else if (entrada == 13){ //Tecla enter

                    i=tamanho;
                }

                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    if(nome[i]==46){
                        deci=0;
                    }
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o numero:%s", nome);
                }

                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o numero:%s", nome);
                }

            break;}

            case 7:{    //Tipo 7 – Letras maiúsculas, minúsculas e números

                if(entrada > 96 && entrada < 123 || entrada== 32 || entrada > 64 && entrada < 91 || entrada > 47 && entrada < 58){
                    nome[i]=entrada;
                    nome[i+1]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                    i++;
                }
                else if (entrada == 13){ //Tecla enter

                    i=tamanho;
                }
                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                }
                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o nome:%s", nome);
                }
            break;}

            case 8:{    //Tipo 8 – Todos os caracteres

                if(entrada > 31 && entrada <127 || entrada > 127 && entrada <255){
                    nome[i]=entrada;
                    nome[i+1]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                    i++;
                }
                else if (entrada == 13){ //Tecla enter

                    i=tamanho;
                }
                else if (entrada == 8){  //Tecla Backspace
                    i--;
                    nome[i]=NULL;
                    clean();
                    printf("Entre com o nome:%s", nome);
                }
                else{ //Teclas a excluir
                 nome[i]=NULL;
                 clean();
                 printf("Entre com o nome:%s", nome);
                }

            break;}

            default:printf("tipo de rotina nao reconhecida.");      // erro de despiste
                }
    }while(i<tamanho);
    clean();
    printf("\nRotina concluida.\nvalor introduzido:%s\n\n", nome);
    free(nome);
}
