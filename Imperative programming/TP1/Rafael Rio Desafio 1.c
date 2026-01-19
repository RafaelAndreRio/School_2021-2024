// Disciplina: Programação Interativa
// Autor: Rafael Rio
// Descrição: Sucessões
// Data: 16/04/2022

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

    int caracter = 178;     //Simbolo "²" Global no setlocal "portugese"

void menu (){       // Menu

        printf("Qual das seguintes funções pretente calcular o limite? opção \"0\" para sair\n\n");

        printf("função 1:\n");
            printf("\t  n%c-n\n\t---------\n\t(n-5)(n-3)\n\n", caracter);
        printf("função 2:\n");
            printf("\t  n\n\t-----\n\t n-2\n\n");
        printf("função 3:\n");
            printf("\t  n+5 \n\n");
}

void main(){

        setlocale(LC_ALL, "portuguese");

    int opcao,simb=152;
    float n=0, calc=0;

        do{         //whille opcao != 0 repete
            menu();
        scanf("%i", &opcao);

        system("cls");

        switch (opcao){

            case 0: break;

            case 1:{    //calculo da primeira função
                    printf("Introduza o número de iterações pretendido\n");
                    scanf("%f", &n);
                    calc=( ( (n*n) -n) / ((n-5)*(2*n-3))); //calculo da 1º funçao
                    printf("Para %.0f iterações  lim f(n) %c %.2f\n\n", n, simb, calc);
                    system("pause");
                    system("cls");
                break;
            }

            case 2:{    //calculo da segunda função
                    do{
                    printf("Introduza o número de iterações pretendido\n");
                    scanf("%f", &n);
                        if(n=2){
                            printf("valor invalido, n nao pode ser 2 pois criaria uma indeterminaçao\n\n");
                        }
                    }while(n=2);

                    calc= n/(n-2);                      //calculo da 2º funçao
                    printf("Para %.0f iterações  lim f(n) %c %.2f\n\n", n, simb, calc);

                    system("pause");
                    system("cls");
                break;
            }

            case 3:{    //calculo da terceira função
                    printf("Introduza o número de iterações pretendido\n");
                    scanf("%f", &n);
                    calc= n+5;                         //calculo da 3º funçao
                    printf("Para %.0f iterações  lim f(n) %c %.2f\n\n", n, simb,calc);


                break;
            }

            default: printf("Opção invalida");
        }

        system("pause");
        system("cls");

        }while(opcao!=0);

}
