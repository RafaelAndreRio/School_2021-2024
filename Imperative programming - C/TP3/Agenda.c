// Disciplina: Programação Imperativa
// Autor: Rafael Rio
// Main: Desafio 3
// Livraria: Rotina Entrada
// Descrição: Criaçao de uma agenda de contactos
// Data: 21/05/2022


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "RotinaChars.h"


typedef struct {
            int id;
            unsigned char nome[20];
            unsigned char telefone[10];
            unsigned char morada[30];
            unsigned char pais[10];
            unsigned char cidade[20];
            unsigned char postal[20];
        } AGENDA;

void bubble_sort_nome(AGENDA *contacto, int n) {
    int i = 0, j = 0;
    AGENDA tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (strcmp(contacto[j].nome , contacto[j+1].nome)>0) {  // swop if order is broken
                tmp = contacto[j];
                contacto[j] = contacto[j+1];
                contacto[j+1]= tmp;
            }
        }
    }
}

void bubble_sort_telefone(AGENDA *contacto, int n) {
    int i = 0, j = 0;
    AGENDA tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (strcmp(contacto[j].telefone , contacto[j+1].telefone)>0) {  // swop if order is broken
                tmp = contacto[j];
                contacto[j] = contacto[j+1];
                contacto[j+1]= tmp;
            }
        }
    }
}

void bubble_sort_morada(AGENDA *contacto, int n) {
    int i = 0, j = 0;
    AGENDA tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (strcmp(contacto[j].morada , contacto[j+1].morada)>0) {  // swop if order is broken
                tmp = contacto[j];
                contacto[j] = contacto[j+1];
                contacto[j+1]= tmp;
            }
        }
    }
}

void bubble_sort_pais(AGENDA *contacto, int n) {
    int i = 0, j = 0;
    AGENDA tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (strcmp(contacto[j].pais , contacto[j+1].pais)>0) {  // swop if order is broken
                tmp = contacto[j];
                contacto[j] = contacto[j+1];
                contacto[j+1]= tmp;
            }
        }
    }
}

void bubble_sort_cidade(AGENDA *contacto, int n) {
    int i = 0, j = 0;
    AGENDA tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (strcmp(contacto[j].cidade , contacto[j+1].cidade)>0) {  // swop if order is broken
                tmp = contacto[j];
                contacto[j] = contacto[j+1];
                contacto[j+1]= tmp;
            }
        }
    }
}

void bubble_sort_postal(AGENDA *contacto, int n) {
    int i = 0, j = 0;
    AGENDA tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (strcmp(contacto[j].postal , contacto[j+1].postal)>0) {  // swop if order is broken
                tmp = contacto[j];
                contacto[j] = contacto[j+1];
                contacto[j+1]= tmp;
            }
        }
    }
}

void bubble_sort_ID(AGENDA *contacto, int n) {
    int i = 0, j = 0;
    AGENDA tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (contacto[j].id > contacto[j+1].id) {  // swop if order is broken
                tmp = contacto[j];
                contacto[j] = contacto[j+1];
                contacto[j+1] = tmp;
            }
        }
    }
}

void mostrar_contacto(AGENDA *contacto, int i,char *arquivo){

    FILE *file_pointer=fopen(arquivo,"r+b");
    fread(&contacto[i],sizeof(AGENDA),1,file_pointer);

                printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);

    fclose(file_pointer);

                }

void introduzir_contacto(AGENDA *contacto,int i){

int n=30;
char *palavra = (char*) calloc(n,sizeof(char));


        printf("ID:%i\n", contacto[i].id);
        printf("Introduz nome:");
            RotinaDados(7,20,0,palavra);
            strcpy(contacto[i].nome,palavra);
            palavra = (char*) calloc(n,sizeof(char));

        printf("Introduz telefone:");
            RotinaDados(5,10,0,palavra);
            strcpy(contacto[i].telefone,palavra);
            palavra = (char*) calloc(n,sizeof(char));

        printf("Introduz morada:");
            RotinaDados(7,30,0,palavra);
            strcpy(contacto[i].morada,palavra);
            strcpy(palavra,"Portugal");

        printf("Introduz paise:");
            RotinaDados(7,10,0,palavra);
            strcpy(contacto[i].pais,palavra);
            palavra = (char*) calloc(n,sizeof(char));

        printf("Introduz cidade:");
            RotinaDados(7,20,0,palavra);
            strcpy(contacto[i].cidade,palavra);
            palavra = (char*) calloc(n,sizeof(char));

        printf("Introduz codigo postal:");
            RotinaDados(9,10,0,palavra);
            strcpy(contacto[i].postal,palavra);
            palavra = (char*) calloc(n,sizeof(char));
}

void criar_novo_contacto(AGENDA contacto[],char *arquivo){               //menu opcao 1

        int i=0;
        FILE *file_pointer=fopen(arquivo,"a+b");

            if(file_pointer==NULL){
                printf("erro ao abrir o ficheiro");
                file_pointer=fopen(arquivo,"a+b");
            }
        fflush(stdin);



           while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1){
               i++;
           }

        contacto[i].id=i+1;
        introduzir_contacto(contacto,i);

             fwrite(&contacto[i],sizeof(AGENDA),1,file_pointer);
             fclose(file_pointer);

system("pause");

    };

void listar_todos_os_contactos(AGENDA contacto[],char arquivo[]){               //menu opcao 2
    int i = 0;
    FILE *file_pointer;

    clean();
    file_pointer= fopen(arquivo,"a+b");

    printf("\n**=========================================================LISTA-DE-CONTACTOS=============================================================**\n");
    printf("||                                                                                                                                        ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1 ){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
        i++;
    }
    printf("**=======================================================================================================================================**\n");
    printf("\n\nForam encontrados %i contactos\n\n\n", i );


    fclose(file_pointer);
    system("pause");
        clean();
        };

void consulta_sequencial(AGENDA contacto[],char *arquivo){               //menu opcao 3
    int i=0,cTecla;
    FILE *file_pointer=fopen(arquivo,"a+b");


        while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1){
               i++;
           }
        i=0;
            printf("Carregue nas setas para passar de contactos,\n Seta para baixo para sair deste menu\n");

                printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);

    do
    {

       cTecla = getch();

            if(cTecla==75 && i!=0){
            system("cls");
            i--;
            printf("Carregue nas setas para passar de contactos,\n Seta para baixo para sair deste menu\n");

                printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);
            }

            else if(cTecla==77 && (contacto[i].id!= NULL||contacto[i].id!=0)){
                 system("cls");
                 i++;
            printf("Carregue nas setas para passar de contactos,\n Seta para baixo para sair deste menu\n");

                printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);
            }

        }while(cTecla != 80);
        system("cls");
        free(contacto);
    fclose(file_pointer);

}

void consulta_por_atributo(AGENDA *contacto, char *arquivo){             //menu opcao 4

        int i, max;

        char opcao, palavra_opcao[10], palavra[30];
        FILE *file_pointer=fopen(arquivo,"r");

        while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1){
            i++;
        }

    max=i;

        do{
        do{
          system("CLS");
  printf("\n\t\t**==============================**\n");
  printf("\t\t||  Menu Consulta por Atributos ||\n");
  printf("\t\t**==============================**");
  printf("\n\n\t\t   Opcao 1 - Nome");
  printf("\n\t\t   Opcao 2 - Num. Telefone");
  printf("\n\t\t   Opcao 3 - Morada");
  printf("\n\t\t   Opcao 4 - Codigo Postal");
  printf("\n\t\t   Opcao 5 - Cidade  ");
  printf("\n\t\t   Opcao 6 - Pais ");

  printf("\n\t\t   Opcao 0 - Menu Principal\n");

  scanf("%c", &opcao);

          }while(opcao<'0' || opcao>'6');

        if(opcao!='0'){
            printf("Qual a palavra que pretente procurar?\n");
            scanf("%s", palavra);
        }
  switch(opcao){

    case 48:
            printf("\n\n\t\t Voltando para o menu...");
            return 0;

    case 49:
            for(i=0; i<max ; i++){

          if(strcmp(contacto[i].nome,palavra)==0){

                printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);

                }
          }


            break;

    case 50:
            for(i=0; i<max ; i++){

          if(strcmp(contacto[i].telefone,palavra)==0){
                printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);
            }
          }
           break;

    case 51:
            for(i=0; i<max ; i++){

          if(strcmp(contacto[i].morada,palavra)==0){
            printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);
            }
          }


            break;

    case 52:
        for(i=0; i<max ; i++){

          if(strcmp(contacto[i].postal,palavra)==0){
            printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);
            }
          }

            break;

    case 53:
        for(i=0; i<max ; i++){

          if(strcmp(contacto[i].cidade,palavra)==0){
            printf("ID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);
            }
          }


            break;

    case 54:
        for(i=0; i<max ; i++){

          if(strcmp(contacto[i].pais,palavra)==0){
            printf("\n\nID: %i\n", contacto[i].id);
                printf("MAIN NOME: %s\n", contacto[i].nome);
                printf("MAIN telefone: %s\n", contacto[i].telefone);
                printf("MAIN morada: %s\n", contacto[i].morada);
                printf("MAIN pais: %s\n", contacto[i].pais);
                printf("MAIN Cidade: %s\n", contacto[i].cidade);
                printf("MAIN Codigo-Postal: %s\n", contacto[i].postal);
            }
          }

            break;

        default:
           printf("\nOpcao Invalida.\n");
           break;
    }



    system("pause");
    system("cls");
        }while(opcao!='0');
        fclose(file_pointer);
  }


void ordenar_contactos(char *arquivo,AGENDA *contacto){                 //menu opcao 5

        int i, max;

        char opcao, palavra_opcao[10], palavra[30];
        FILE *file_pointer=fopen(arquivo,"r");

        while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1){
            i++;
        }

    max=i;

        do{
        do{
          system("CLS");
    printf("\n\t\t**==============================**\n");
    printf("\t\t||  Menu Ordenar por Atributos ||\n");
    printf("\t\t**==============================**\n");
    printf("\n\t\t   Opcao 1 - Nome");
    printf("\n\t\t   Opcao 2 - Num. Telefone");
    printf("\n\t\t   Opcao 3 - Morada");
    printf("\n\t\t   Opcao 4 - Codigo Postal");
    printf("\n\t\t   Opcao 5 - Cidade");
    printf("\n\t\t   Opcao 6 - Pais");
    printf("\n\t\t   Opcao 7 - ID");

  printf("\n\t\t   Opcao 0 - Menu Principal\n");


    printf("Quer ordenar por que atributo?\n");
    scanf("%c", &opcao);

          }while(opcao<'0' || opcao>'7');

  switch(opcao){

    case 48:
            printf("\n\n\t\t Voltando para o menu...");
            return 0;

    case 49:    //nome
            bubble_sort_nome(contacto,max);

    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  for(i=0; i<max;i++){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
    }
    printf("**=======================================================================================================================================**\n");
            break;

    case 50:    //Num. Telefone
            bubble_sort_telefone(contacto,max);

    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  for(i=0; i<max;i++){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
    }
    printf("**=======================================================================================================================================**\n");
           break;

    case 51:    //Morada
            bubble_sort_morada(contacto,max);

    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  for(i=0; i<max;i++){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
    }
    printf("**=======================================================================================================================================**\n");
            break;

    case 52:    //Codigo Postal
            bubble_sort_postal(contacto,max);

    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  for(i=0; i<max;i++){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
    }
    printf("**=======================================================================================================================================**\n");
            break;

    case 53:    //Cidade
            bubble_sort_cidade(contacto,max);

    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  for(i=0; i<max;i++){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
    }
    printf("**=======================================================================================================================================**\n");
            break;

    case 54:    //Pais
            bubble_sort_pais(contacto,max);

    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  for(i=0; i<max;i++){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
    }
    printf("**=======================================================================================================================================**\n");
            break;

    case 55:    //ID
            bubble_sort_ID(contacto,max);

    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  for(i=0; i<max;i++){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
    }
    printf("**=======================================================================================================================================**\n");


            break;

        default:
           printf("\nOpcao Invalida.\n");
           break;
    }



    system("pause");
    system("cls");
        }while(opcao!='0');
        fclose(file_pointer);
        system("cls");
  }

    void modificar_contacto(char *arquivo, AGENDA *contacto){                //menu opcao 6



    FILE *file_pointer;
     int i = 0,k ,max=0,opcao=1, n=30;
     char letra;
     char *palavra = (char*) calloc(n,sizeof(char));


    clean();
    file_pointer= fopen(arquivo,"a+b");

    printf("\n**=========================================================LISTA-DE-CONTACTOS=============================================================**\n");
    printf("||                                                                                                                                        ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1 ){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
        i++;
    }
            max=i;

    printf("**=======================================================================================================================================**\n");

          printf("Escolha o contacto pelo id o contacto que quer alterar: ");
          scanf("%i", &k);
          k=k-1;
          system ("cls");
        do{
          system("CLS");
    printf("\n\t\t**==============================**\n");
    printf("\t\t||  Menu Ordenar por Atributos ||\n");
    printf("\t\t**==============================**\n");
    printf("\n\t\t   Opcao 1 - Nome");
    printf("\n\t\t   Opcao 2 - Num. Telefone");
    printf("\n\t\t   Opcao 3 - Morada");
    printf("\n\t\t   Opcao 4 - Codigo Postal");
    printf("\n\t\t   Opcao 5 - Cidade");
    printf("\n\t\t   Opcao 6 - Pais");

  printf("\n\t\t   Opcao 0 - Menu Principal\n");


    printf("Quer ordenar por que atributo?\n");
    scanf("%c", &opcao);

          }while(opcao<'0' || opcao>'6');
          switch(opcao){

    case 48:
            printf("\n\n\t\t Voltando para o menu...");
            break;
    case 49:    //nome
        printf("introduza o novo Nome:\n");

            RotinaDados(7,20,0,palavra);
            strcpy(contacto[k].nome,palavra);
            palavra = (char*) calloc(n,sizeof(char));
            break;

    case 50:    //Num. Telefone
        printf("introduza o novo Numero de Telefone:\n");
            RotinaDados(5,10,0,palavra);
            strcpy(contacto[k].telefone,palavra);
            palavra = (char*) calloc(n,sizeof(char));
            break;

    case 51:    //Morada
            printf("introduza o nova morada:\n");
            RotinaDados(7,30,0,palavra);
            strcpy(contacto[k].morada,palavra);
            strcpy(palavra,"Portugal");
            break;

    case 52:    //Codigo Postal
            printf("introduza o novo codigo de postal:\n");
            RotinaDados(9,10,0,palavra);
            strcpy(contacto[k].postal,palavra);
            palavra = (char*) calloc(n,sizeof(char));

            break;

    case 53:    //Cidade
            printf("introduza o nova Cidade:\n");
            RotinaDados(7,10,0,palavra);
            strcpy(contacto[k].pais,palavra);
            palavra = (char*) calloc(n,sizeof(char));


            break;

    case 54:    //Pais
            printf("introduza o novo País:\n");
            RotinaDados(7,20,0,palavra);
            strcpy(contacto[k].cidade,palavra);
            palavra = (char*) calloc(n,sizeof(char));

            break;


        default:
           printf("\nOpcao Invalida.\n");
           break;
    }

    file_pointer= fopen(arquivo,"w+b");

        for(i=0; i< max;i++){
        fwrite(&contacto[i],sizeof(AGENDA),1,file_pointer);

        }
    fclose(file_pointer);


        i=0;

    free(contacto);
file_pointer=fopen(arquivo,"r+b");
             printf("\n**=========================================================LISTA-DE-CONTACTOS=============================================================**\n");
    printf("||                                                                                                                                        ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

           while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1 ){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
        i++;
            }
               printf("**=======================================================================================================================================**\n");




    system("pause");
    system("cls");
        fclose(file_pointer);
        system("cls");
        };

void remover_contacto(char *arquivo, AGENDA *contacto){                  //menu opcao 7


    FILE *file_pointer;
     int i = 0,n,k,max=0;
     char letra;

    clean();
    file_pointer= fopen(arquivo,"a+b");

    printf("\n**=========================================================LISTA-DE-CONTACTOS=============================================================**\n");
    printf("||                                                                                                                                        ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

  while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1 ){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
        i++;
    }
            max=i;

    printf("**=======================================================================================================================================**\n");

          printf("Escolha o contacto pelo id: ");
          scanf("%i", &n);
          n=n-1;
          system ("cls");
    printf("\n**=========================================================LISTA-DE-CONTACTOS=============================================================**\n");
    printf("||                                                                                                                                        ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[n].id,contacto[n].nome,contacto[n].telefone,contacto[n].morada,contacto[n].postal,contacto[n].cidade,contacto[n].pais);
    printf("**=======================================================================================================================================**\n");
    printf("Deseja mesmo apagar este contacto? S/N\n");

        fflush(stdin);
    scanf(" %c", &letra);
    system("cls");

    if(letra=='s' || letra=='S'){


        for(k=0;n+k<i;k++){
                strcpy(contacto[n+k].nome , contacto[n+k+1].nome);
                strcpy(contacto[n+k].telefone , contacto[n+k+1].telefone);
                strcpy(contacto[n+k].morada , contacto[n+k+1].morada);
                strcpy(contacto[n+k].pais , contacto[n+k+1].pais);
                strcpy(contacto[n+k].cidade , contacto[n+k+1].cidade);
                strcpy(contacto[n+k].postal , contacto[n+k+1].postal);

        }
    file_pointer= fopen(arquivo,"w+b");

        for(i=0; i< max-1;i++){
        fwrite(&contacto[i],sizeof(AGENDA),1,file_pointer);

        }
    fclose(file_pointer);


        i=0;

    free(contacto);
file_pointer=fopen(arquivo,"r+b");
             printf("\n**=========================================================LISTA-DE-CONTACTOS=============================================================**\n");
    printf("||                                                                                                                                        ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");
    printf("||ID:  |Nome:               |Telefone: |Morada:                       |Cod.Postal:|Cidade:             |Pais:                             ||\n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------||\n");

           while(fread(&contacto[i],sizeof(AGENDA),1,file_pointer) == 1 ){

    printf("||%-5i|%-30s|%-10s|%-35s|%-10s|%-20s|%-20s||\n", contacto[i].id,contacto[i].nome,contacto[i].telefone,contacto[i].morada,contacto[i].postal,contacto[i].cidade,contacto[i].pais);
        i++;
            }
               printf("**=======================================================================================================================================**\n");

           }


fclose(file_pointer);
    };

void apagar_agenda(char *arquivo){                     //menu opcao 8
        char check;
        //FILE *file_pointer=fopen(file_pointer,"r");

        lcaract(1,10);       //imprimir linha
        lcaract(3,9);       //imprimir tabs
        lcaract(42,'*');    //imprimir linha de *
        lcaract(1,10);       //imprimir linha
        lcaract(3,9);       //imprimir tabs
        system("color 04");
        printf("*Atenção! Esta operação não é reversivel!*");

        lcaract(1,10);       //imprimir linha
        lcaract(3,9);       //imprimir tabs
        lcaract(42,'*');    //imprimir linha de *
        lcaract(3,10);       //imprimir linha
        system("pause");
        system("cls");
        system("color 0F");

        lcaract(3,9);       //imprimir tabs
            printf("Tem a certeza que pretende apagar a agenta toda?");
        lcaract(1,10);       //imprimir linha
        lcaract(2,9);       //imprimir tabs
            printf("Todos os contactos serão apagados. Esta operaçao não é reversivel.\n");


        lcaract(2,10);       //imprimir linha
        lcaract(4,9);       //imprimir tabs
                lcaract(28,'=');       //imprimir linha
        lcaract(1,10);       //imprimir linha
        lcaract(4,9);       //imprimir tabs
            printf("= Prima \"s\" para confirmar =");
                    lcaract(1,10);       //imprimir linha
        lcaract(4,9);       //imprimir tabs
                lcaract(28,'=');       //imprimir linha
        lcaract(2,10);       //imprimir linha
        lcaract(2,9);       //imprimir tabs
            printf("     = Carregue em outra tecla para cancelar a operação =");
        lcaract(3,10);       //imprimir linha

            printf("opção:");

            scanf(" %c", &check);


        if(check == 's' || check == 'S'){

            if( remove( arquivo ) == -1 )
                printf("Nao pode ser apagado o ficheiro %s\n", arquivo);
            else
                printf( "Ficheiro %s apagado\n", arquivo);

        system("pause");
        };

        lcaract(3,10);       //imprimir linha

    };

void infomacoes_extras(){                 //menu opcao 9
            lcaract(80,'*');
            lcaract(4,10);

            printf("\tCaracteristicas do trabalho:\n");

            lcaract(1,10);

            printf("\t\tDisciplina: Programação Imperativa\n");
            printf("\t\tProfessor: Melo Pereira\n");
            printf("\t\tAutor: Rafael Rio\n");
            printf("\t\tDescrição: Criaçao de uma agenda de contactos\n");
            printf("\t\tDesenvolvimento: âmbito académico\n");
            printf("\t\tAno lectivo: 2021/2022\n");
            printf("\t\tAno-Semestre: 1ºAno-2ºSemestre\n");

            lcaract(4,10);
            lcaract(80,'*');
            lcaract(2,10);
            system("pause");
    };

void sair_programa(char *arquivo){                     //menu opcao 0

            lcaract(6,10);      // printar linha branca
            lcaract(3,9);       //imprimir tabs
            lcaract(81,'*');    //81 *
            lcaract(1,10);      // printar linha branca
            lcaract(3,9);       //imprimir tabs
            lcaract(1,'*');
            lcaract(79,' ');    //imprimir 79 espaços
            lcaract(1,'*');
            lcaract(1,10);      // printar linha branca
            lcaract(3,9);       //imprimir tabs

            printf("*\t\t    Obrigado pela sua visita, o Programa fechou  \t\t*\n");
            lcaract(3,9);       //imprimir tabs
            lcaract(1,'*');
            lcaract(79,' ');    //imprimir 79 espaços
            lcaract(1,'*');
            lcaract(1,10);      // printar linha branca
            lcaract(3,9);       //imprimir tabs
            lcaract(81,'*');    //81 *
            lcaract(10,10);      // printar linha branca
    }

void opcao_menu(int *opcao){                          //apresentaçao de menu, e opção

    char suport;

        do{
            printf("\t\tDesafio Nº3 - Agenda Telefonica\n");
            printf("\tProgramação Imperativa, 1º Ano, 2º Semestre 2022\n");

        lcaract(80,'*');
        lcaract(1,10);
            printf("\t Bem vindo a sua Agenda de contactos\n");
        lcaract(1,10);

            printf("\t\t1: Criar Novo Contacto\n");
            printf("\t\t2: Consulta Sequencial\n");
            printf("\t\t3: Listar todos os contactos\n");
            printf("\t\t4: Consulta por Atributo\n");
            printf("\t\t5: Ordenar Contactos\n");
            printf("\t\t6: Modificar Contacto\n");
            printf("\t\t7: Remover Contacto\n");
            printf("\t\t8: Apagar Agenda\n");
            printf("\t\t9: Infomações extras\n\n");
            printf("\t\t0: para sair do programa\n");

        lcaract(80,'*');
        lcaract(2,10);
            printf("Escolha a opção que pretende\nTipo:");
            suport=getche();

        clean();
        }while(suport>'9' || suport<'0');

        *opcao=suport;
}

void lista_agenda(char opcao, char *arquivo, AGENDA *contacto){
        switch(opcao){
            case '1':{
                    criar_novo_contacto(contacto,arquivo);
                    break;}

            case '2':{
                    consulta_sequencial(contacto,arquivo);
                    break;}

            case '3':{
                    listar_todos_os_contactos(contacto,arquivo);
                    break;}

            case '4':{
                    consulta_por_atributo(contacto, arquivo);
                    break;}

            case '5':{
                    ordenar_contactos(arquivo, contacto);
                    break;}


            case '6':{
                    modificar_contacto(arquivo,contacto);
                    break;}

            case '7':{
                    remover_contacto(arquivo, contacto);
                    break;}

            case '8':{
                    apagar_agenda(arquivo);
                    break;}

            case '9':{
                    infomacoes_extras();
                    break;}

            case '0':{

                    sair_programa(arquivo);
                    break;}
        }
}

void main(){

  setlocale(LC_ALL, "Portuguese");

    FILE *file_pointer;
    char *arquivo={"Rafael_Rio.dat"}, *tipo={"r+"};
    char *opcao;
    int ptr_suport;
    AGENDA *contacto = (AGENDA*) calloc(100,sizeof(*contacto));

            do{

                ptr_suport=&opcao;
                opcao_menu(ptr_suport);       //opção tem o valor

                lista_agenda(opcao,arquivo,contacto);

            }while(opcao!='0');

            free(contacto);

}
