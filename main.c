#include <stdio.h>
#include <stdlib.h>

typedef int *p_vetor;
typedef int **p_matriz;

p_vetor construirVetor(unsigned int qtd_itens){

    p_vetor vetor;
    vetor = malloc(sizeof(int) * qtd_itens);
    return vetor;
}
p_matriz construirMatriz(unsigned int qtd_linhas, unsigned int qtd_colunas)

{
    p_matriz matriz;
    matriz = malloc(sizeof(p_vetor) * qtd_linhas);
    
    for (int i = 0; i < qtd_linhas; i++)
   {
      matriz[i] = construirVetor(qtd_colunas);

    }
    return matriz;
}

void lerDadosMatriz(p_matriz matriz, unsigned int qtd_linhas, unsigned int qtd_colunas)

{
    for (int i = 0; i < qtd_linhas; i++)
        {
        for (int j = 0; j < qtd_colunas; j++)

        {

            scanf("%d", &matriz[i][j]);

        }

    }

}

void imprimirMatriz(p_matriz matriz, unsigned int qtd_linhas, unsigned int qtd_colunas)

{

    if (qtd_linhas == 0)

    {
     printf("[matriz vazia]\n");

    }

    else

    {

        for (int i = 0; i < qtd_linhas; i++)

        {

            for (int j = 0; j < qtd_colunas; j++)

            {

                (j == 0) ? printf("%d", matriz[i][j]) : printf(" %d", matriz[i][j]);

            }

            printf("\n");

        }

    }

}

void destruirVetor(p_vetor vetor)

{

    free(vetor);

}

void destruirMatriz(p_matriz matriz, int qtd_linhas)

{

    for (int i = 0; i < qtd_linhas; i++)

    {

        destruirVetor(matriz[i]);

    }
    free(matriz);

}

int main()

{

    // dados

    unsigned int qtd_linhas = 0;

    unsigned int qtd_colunas = 0;

    p_matriz minha_matriz;

    // 1 - Leia as dimensoes de uma matriz (linha e coluna)

    scanf("%u %u", &qtd_linhas, &qtd_colunas);



    // 2 - Aloque dinamicamente a memória para a matriz

    minha_matriz = construirMatriz(qtd_linhas, qtd_colunas);



    // 3 - Leia os dados da matriz

    lerDadosMatriz(minha_matriz, qtd_linhas, qtd_colunas);



    // 4 - Apresente os dados da matriz

    imprimirMatriz(minha_matriz, qtd_linhas, qtd_colunas);



    // 5 - Desaloque a memória alocada

    destruirMatriz(minha_matriz, qtd_linhas);


    return 0;
}
