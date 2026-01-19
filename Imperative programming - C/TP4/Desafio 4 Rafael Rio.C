// Disciplina: Programação Imperativa
// Autor: Rafael Rio
// Main: Desafio 4
// Descrição: ler, caracteristicas do CSV,organizar e escrever um novo CSV.
// Data: 21/05/2022

//**************IMPORTANTE**************
//
// ESTE PROGRAMA SO PODE ABRIR ".CSV"
// PARA ABRIR OUTROS FICHEIROS PRECISA MUDAR
// A VARIAVEL GLOBAR ESTENSAO
//
//**************IMPORTANTE**************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>


//Variaveis Globais
    FILE *file_pointer;
    char *arquivo =(char*)calloc(20,sizeof(char));
    char suport_name[20];   //Variavel para criar novo file
    char *extensao=".csv";  //só pode abrir CSV
    //char *extensao=".txt";
    char ***matriz;



//Funções

//Funções de Files
    //Abre o FILE fopen()
void abrirFile(char *tipo)
{
    file_pointer = fopen(arquivo, tipo);

    if(file_pointer != NULL){
        printf("Arquivo lido com sucesso!\n");
    }else{
        printf("Erro ao carregar o arquivo!\n Ficheiro pode nao existir");
    }
}

    //fecha o file e confirma se foi fechado
void fecharFile()
{
    if(file_pointer!=NULL)
    {
        if((int) fclose(file_pointer) == EOF)
        {
            printf("Erro ao fechar o arquivo!\n");
        }
    }

}

//repete caracteres         (10) = \n
void lcaract(int nColunas, char car)
{
    int i;
    for(i=0;i<nColunas;i++)     printf("%c",car);
}


//Funções do programa

//Pede o nome do ficheiro e junta a extenção declarada na variavel global
char nome()
{
        printf ( "Informe o nome do arquivo a ser lido: \n" );
        fflush(stdin);

        gets(arquivo);
        strcpy(suport_name,arquivo);
        strcat(arquivo,extensao);
}

//fechar o programa
void fim_programa()
{

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

    free(file_pointer);
    free(arquivo);
    free(extensao);
}

//imprime o ficheiro todo no ecra
void imprime_file()
{
    abrirFile("r");
    char texto;

    while((texto=getc(file_pointer))!= EOF)
    {
        printf("%c", texto);
    }
    lcaract(1,10);
    system("pause");
    fecharFile();
}

//Conta o numero de linhas do FILE
int contagemLinhas()
{
    abrirFile("r");
    char texto;
    int contador=0;
    if(file_pointer!=NULL)
    {
        while((texto=getc(file_pointer))!= EOF)
        {
            if(texto== '\n')
            {
                contador++;
            }
        }
    }
    fecharFile();
    return contador;
}

//Mostra a quantidade de linhas
void mostrarLinhas()
{
    int linhas;
    linhas=contagemLinhas();
    printf("O Ficheiro contem %i linhas\n",linhas);
    system("pause");
}

//Conta o numero de colunas do FILE
int contagemColunas()
{
abrirFile("r");
    char texto;
    int contador=0;
    int verificacao=0;

    if(file_pointer!=NULL)
    {
        while(texto!= '\n' && verificacao!=1){
            (texto=fgetc(file_pointer));

            if(texto== ',' || texto== '\t' || texto== ';' || texto== '\n')
            {
                contador++;
            }
        }

    }

    fecharFile();
    return contador;
}

//Mostra a quantidade de colunas
void mostrarColunas()
{
        int colunas;
    colunas=contagemColunas();
    printf("O Ficheiro contem %i colunas\n", colunas);
    system("pause");
}

//conta as palavras do ficheiro
void quantas_palavras()
{
abrirFile("r");
    char texto;
    int contador=0;
    if(file_pointer!=NULL)
    {

        while((texto=fgetc(file_pointer))!= EOF)
        {
            if( (texto== ',' || texto== ' ' || texto== '\t' || texto== ';' || texto== '\n'))
            {
                contador++;
            }
        }
        printf("O Ficheiro contem %i palavras\n",contador);
    }

    fecharFile();

       system("pause");
}

//reserva uma matriz com (N)colunas e (N)Linhas vindas de outra funçao
void criarMatriz(int colunas, int linhas)
{
    int i=0, k=0,z=0;

        matriz=(char***)calloc(linhas,sizeof(char**));
        if(!matriz)       //alocação NULL
        {
            printf("Problemas no 1º nivel de alocação de memoria/falta de memoria");
            return;
        }

    for(i=0 ; i<colunas ; i++)
    {
        matriz[i]=(char**)calloc(colunas,sizeof(char*));
        if(!matriz[i])       //alocação NULL
        {
            printf("Problemas no 2º nivel de alocação de memoria/falta de memoria");
            return;
        }
    }


    for (i=0; i<colunas ; i++)
    {
        for(k=0; k<linhas ; k++)
        {
            matriz[i][k]=(char*)calloc(30,sizeof(char));
            if(!matriz[i][k])       //alocação NULL
            {
                printf("Problemas no 3º nivel de alocação de memoria/falta de memoria");
                return;
            }
        }
    }
}

//Escreve para o buffer na matriz criada anteriormente (algo esta errado nesta função)
void escreverMatriz(int linhas, int colunas)
{
    int i=0, k=0, z=0;
    char texto;

    abrirFile("r");

        while((texto=getc(file_pointer))!= EOF)
        {

             if(texto == '\n'&& k!=0 && i<linhas)
            {
                i++;
                k=0;
                z=0;
            }
            else if(texto=='\t' || texto==',' || texto==';' && k<colunas)
            {
                printf("%s\n", matriz[i][k]);
                k++;
                z=0;
            }
            else if( (texto!='\0'))
            {
               /* matriz[i][k]=(char *) realloc( matriz[i][k], (z+2)*sizeof(char) );
                        if(matriz[i][k]==NULL)       //alocação NULL
                        {
                            printf("Problemas no 3º nivel de alocação de memoria/falta de memoria");
                            return;
                        }*/
                matriz[i][k][z]=texto;
                matriz[i][k][z+1]='\0';
                z++;
            }


            /*if( (texto!='\0') && (texto!= ';' ) && (texto!='\n') && (texto !=',') && (texto!='\t') && (texto!=EOF))
            {
                matriz[i][k]=(char *) realloc( matriz[i][k], (z+2)*sizeof(char) );
                        if(!matriz[i][k])       //alocação NULL
                        {
                            printf("Problemas no 3º nivel de alocação de memoria/falta de memoria");
                            return;
                        }
                matriz[i][k][z]=texto;
                matriz[i][k][z+1]='\0';

                z++;
            }
            else if(texto=='\t' || texto==',' || texto==';' && k<colunas)
            {
                k++;
                z=0;
            }
            else if(texto == '\n'&& k!=0 && i<linhas)
            {
                i++;
                k=0;
                z=0;
            }*/
        }
    fecharFile();
}

//liberta a memoria da matriz de (N)linhas (N)colunas
void limparMatriz(int linhas,int colunas)
{
    int i=0 , k=0 , z=0;

    for(i=0; i<linhas ; i++)
        {
            for(k=0; k<colunas ; k++)
                {
                    free(matriz[i][k]);
                }
        }

    for(i=0; i<linhas ; i++)
        {
            free(matriz[i]);
        }
}

//Imprime no ecra a matriz do Buffer
void mostrarMatriz(int linhas,int colunas)
{
    int i=0,k=0 ,z=0;

    for(k=0 ; k<colunas ; k++)
        printf("coluna %i\t\t", k+1);
    printf("\n");

        for(i=0;i<linhas; i++)
        {
            for(k=0; k<colunas; k++)
            {
                printf("%s\t\t\t", matriz[i][k]);
            }
            printf("\n");
        }
}

//Funçao para ordenar a coluna
void bubble_sort_Matriz(int n,int coluna) {
    int i = 0, j = 0;
    char **temp=(char**)calloc(coluna,sizeof(char*));

    for(i=0 ; i< coluna ; i++)
        temp[i]=(char*)calloc(30,sizeof(char));

    coluna=coluna-1;

    for (i = 0; i < n; i++) {   // loop n times - 1 per element

        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already

            if (strcmp(matriz[j][coluna], matriz[j+1][coluna])>0) {  // swop if order is broken

                temp = matriz[j];
                matriz[j] = matriz[j+1];
                matriz[j+1] = temp;
            }
        }
    }
}

//Encadeamento de funçoes para ordenar, e escrever um ficheiro novo ".CSV"
void escrever_ordenado(int n)
{
    int i=0, k=0,z=0, colunas=0,linhas=0;
    char ch,teste[1];
    char *nome_do_ficheiro_final=(char*)calloc(40,sizeof(char));
    char coluna[]=" Coluna ";
    teste[0]=n+'0'; //converter numero int em numero char

    colunas=contagemColunas();
    linhas=contagemLinhas();

    //construção do nome do File, nome,coluna,numero_coluna,extensao
    strcat(nome_do_ficheiro_final,suport_name);     //Recebe o nome original
    strcat(nome_do_ficheiro_final,coluna);         //Junta a palavra Coluna
    strcat(nome_do_ficheiro_final,teste);           //Junta o numero da coluna ordenada
    strcat(nome_do_ficheiro_final,extensao);        //A extensao do ficheiro definida na variavel global

    FILE *ptr_new_file;
        ptr_new_file=fopen(nome_do_ficheiro_final,"w+");
            if(ptr_new_file==NULL)
                {
                    printf("Erro ao Criar o ficheiro %s", nome_do_ficheiro_final);
                    //exit(1);
                }

        for(i=0;i<linhas ;i++)
            {
                for(k=0; k<colunas ;k++)
                {
                    for(z=0; z<strlen(matriz[i][k]) ; z++)
                    {
                        ch=matriz[i][k][z];
                        fputc ( ch, ptr_new_file );
                    }
                 //   ch='\t';
                   // fputc ( ch, ptr_new_file );
                    ch=';';
                    fputc ( ch, ptr_new_file );
                }
                ch='\n';
                fputc ( ch, ptr_new_file );
            }

fclose(ptr_new_file);
}


//preparação da matriz e definição dos parametros para ordenar e/ou guardar novo file
void ordenacao()
 {
      int colunas=0,linhas=0, opcao=0;
      char texto;
        colunas=contagemColunas();
        linhas=contagemLinhas();
        criarMatriz(linhas,colunas);
           // system("cls");

        escreverMatriz(linhas,colunas);     //esta a dar problemas aqui
        mostrarMatriz(linhas,colunas);

        do
        {
            printf("\nQual é o indice da coluna que pretende organizar? 0 para voltar \nFormato numerico:");
            scanf("%i", &opcao);

            system("cls");
            if(opcao<=colunas && opcao>0)
            {
                bubble_sort_Matriz(linhas,opcao);
                mostrarMatriz(linhas,colunas);
                    printf("Deseja criar um ficheiro novo com está ordenação? \t s-sim\tn-não\n");
                    fflush(stdin);
                                scanf("%c", &texto);
                                if(texto=='s'|| texto=='S')
                                {
                                    escrever_ordenado(opcao);
                                    break;
                                }

            }
            else if (opcao==0)
            {
                system("cls");
            }
            else
            {
                printf("opção invalida");
            }
        }while( opcao!=0);

    limparMatriz(linhas,colunas);

 }

// switch menu
void lista(char opcao)
{

    switch(opcao)
    {
        case '1':
            {
                imprime_file();
                break;
            }
        case '2':
            {
                quantas_palavras();
                break;
            }
        case '3':
            {
                mostrarColunas();
                break;
            }
        case '4':
            {
                mostrarLinhas();
                break;
            }
        case '5':
            {
                ordenacao();
                break;
            }

        case '6':
            {
                nome();
                break;
            }
        case '0':
            fim_programa();
        break;
    }
}

 //Menu
char menu()
{
    char opcao;
    do
    {
        printf("1-Imprimir file\n");
        printf("2-Quantas palavras\n");
        printf("3-Contagem de colunas\n");
        printf("4-Quantas linhas\n");
        printf("5-Ordenação por campo e guardar em CSV\n");
        printf("6-Escolher outro ficheiro\n");
        printf("0-Fechar o Programa\n");

        scanf("%c", &opcao);
        system("cls");


    }while(opcao<'0' || opcao>'8' ); //'0'=48 , '9'=57

}

int main(){
    setlocale(LC_ALL, "portuguese");
    char opcao;

    nome();

    do
    {
        opcao = menu();
        lista(opcao);
    }while(opcao!='0');

}
