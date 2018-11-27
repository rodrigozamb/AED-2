#include"TrabalhoFinalAED22.h"
#include<stdio.h>
#include<stdlib.h>

Grafo* cria_grafo(int vert)
{
    Grafo *G;

    G=(Grafo*)malloc(sizeof(Grafo));
    if(G==NULL)
    {
        free(G);
        return NULL;
    }
    G->qtde_vertices=vert;


    G->aresta=(No**)malloc(sizeof(No));
    int i;
    for(i=0; i<G->qtde_vertices; i++)
    {
        G->aresta[i]=NULL;
    }
    if(G->aresta==NULL)
    {
        free(G->aresta);
        free(G->grau);
        free(G);
        return NULL;
    }

}


void libera_grafo(Grafo **G)
{
    if((*G)!=NULL)
    {
        int i;
        No *aux,*ant;
        for(i=0; i<(*G)->qtde_vertices; i++)
        {
            aux=(*G)->aresta[i];
            ant=NULL;
            while(aux!=NULL)
            {
                ant=aux;
                aux=aux->prox;
                free(ant);
            }
        }

        free((*G)->grau);
        free(*G);
        *G=NULL;
    }


}


void busca_profundidade(Grafo *G,int v,int *visitados)
{
    visitados[v]=1;

    printf("  %d  ",v);

    No *aux;
    aux=G->aresta[v];


    while(aux!=NULL)
    {
        if(visitados[aux->vertice]==0)
        {
            busca_profundidade(G,aux->vertice,visitados);
        }

        aux=aux->prox;
    }

}


float** CriarMatriz(int Linhas,int Colunas)
{
    int i,j;

    float **m = (float**)calloc(Linhas,sizeof(float*));

    for (i = 0; i < Linhas; i++)
    {
        m[i] = (float*) calloc(Colunas,sizeof(float));
        for (j = 0; j < Colunas; j++)
        {
            m[i][j] = 0;
        }
    }
    return m; //Retorna o Ponteiro para a Matriz Alocada
}

void mostraMatriz(float** m,int Linhas,int Colunas)
{

    int i,j;

    for(i=0; i<Linhas; i++)
    {
        for(j=0; j<Colunas; j++)
        {
            printf("[%d][%d] : %f ",i,j,m[i][j]);
        }
        printf("\n");
    }
}

void InserirMatriz(float** m,int v1,int v2,float feromonio,int tam)
{
    m[v1][v2] = feromonio;
    m[v2][v1] = feromonio;
}

void RemoverMatriz(float** m,int v1,int v2,int tam)
{
    m[v1][v2] = 0;
    m[v2][v1] = 0;
}

int hashValue(char * frase){
    int val=7,i;
    for(i=0;i<strlen(frase);i++){
        val = 31*val+(int)frase[i];
    }
    return val;
}
