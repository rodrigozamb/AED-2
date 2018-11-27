#include"TrabalhoFinalAED2.h"
#include<stdio.h>
#include<stdlib.h>

Grafo *cria_grafo(int vert)
{
    Grafo *G;

    G=(Grafo*)malloc(sizeof(Grafo));
    if(G==NULL)
    {
        free(G);
        return NULL;
    }
    G->qtde_vertices=vert;
    G->qtde_arestas=0;


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

int insere_arestaN(Grafo *G,int v1,int v2)
{
    if(G==NULL || (v1<0 || v2<0))
    {
        return -1;
    }

    No *aux;

    aux=G->aresta[v1];
    while(aux!=NULL && strcmp(G->n))
    {
        aux=aux->prox;
    }
    if(aux!=NULL)
    {
        return 0;
    }

    No *novo=(No*)malloc(sizeof(No));
    if(novo!=NULL)
    {
        novo->vertice=v2;
        novo->peso=peso;
        novo->prox=G->aresta[v1];
        G->aresta[v1]=novo;
    }

    G->qtde_arestas++;
    G->grau[v1]++;
    G->grau[v2]++;

    No *aux2;

    aux2=G->aresta[v2];
    while(aux2!=NULL && aux2->vertice!=v1)
    {
        aux2=aux2->prox;
    }
    if(aux2!=NULL)
    {
        return 0;
    }

    No *novo1=(No*)malloc(sizeof(No));
    if(novo1!=NULL)
    {
        novo1->vertice=v1;
        novo1->peso=peso;
        novo1->prox=G->aresta[v2];
        G->aresta[v2]=novo1;
    }

    return 1;
}


void mostra_grafo(Grafo *G)
{
    if(G==NULL)
    {
        printf("Grafo não existe");
    }
    else if(G->qtde_arestas==0)
    {
        printf("Grafo Vazio");
    }
    No *aux;
    int i;
    for(i=0; i<=G->qtde_vertices; i++)
    {
        aux=G->aresta[i];
        if(G->qtde_vertices!=i)printf("Vertice [%d]: \n",i);
        while(aux!=NULL)
        {
            printf("( %d , %d )->Peso: %f  \n",i,aux->vertice,aux->peso);
            aux=aux->prox;

        }
        printf("\n\n");

    }

}


int verifica_aresta(Grafo *G,int v1,int v2)
{
    if(G==NULL || (v1<0 || v2<0))
    {
        return -1;
    }
    No *aux;
    aux=G->aresta[v1];
    while(aux!=NULL && aux->vertice!=v2)
    {
        aux=aux->prox;
    }
    if(aux==NULL)
    {
        return 0;
    }

    return 1;
}

int remove_arestaN(Grafo *G,int v1,int v2)
{
    if(G==NULL || (v1<0 || v2<0))
    {
        return -1;
    }

    No *aux;
    aux=G->aresta[v1];
    while(aux!=NULL && aux->vertice!=v2)
    {
        aux=aux->prox;
    }
    if(aux==NULL)
    {
        return 0;
    }
    else
    {
        No *aux1,*ant;

        ant=NULL;
        aux1=G->aresta[v1];

        while(aux1->vertice!=v2)
        {
            ant=aux1;
            aux1=aux1->prox;

        }
        ant->prox=aux1->prox;
        free(aux1);
        G->qtde_arestas--;
        G->grau[v1]--;
        G->grau[v2]--;
    }

    No *aux0;
    aux0=G->aresta[v2];
    while(aux0!=NULL && aux0->vertice!=v1)
    {
        aux0=aux0->prox;
    }
    if(aux0==NULL)
    {
        return 0;
    }

    No *aux2,*ant2;

    ant2=NULL;
    aux2=G->aresta[v2];

    while(aux2->vertice!=v1)
    {
        ant2=aux2;
        aux2=aux2->prox;

    }
    ant2->prox=aux2->prox;
    free(aux2);

    return 1;
}

int consulta_aresta(Grafo *G,int v1,int v2,float *peso)
{

    if(G==NULL || (v1<0 || v2<0))
    {
        return -1;
    }

    No *aux;
    aux=G->aresta[v1];
    while(aux!=NULL && aux->vertice!=v2)
    {
        aux=aux->prox;
    }
    if(aux==NULL)
    {
        return 0;
    }

    No *aux1;
    aux1=G->aresta[v1];
    while(aux1->vertice!=v2)
    {
        aux1=aux1->prox;
    }

    *peso=aux1->peso;

    return 1;
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

void mostra_adjacentes(Grafo *G,int v)
{
    if(G!=NULL && v>=0)
    {

        No *aux;
        aux=G->aresta[v];
        if(aux==NULL)
        {
            printf("O vertice não possui adjacentes");
        }
        else
        {
            while(aux!=NULL)
            {
                printf("  V -> %d = %f,",aux->vertice,aux->peso);
                aux=aux->prox;
            }

        }

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

void DPS(Grafo *G,int v)
{

    int *visitados;

    visitados=(int*)calloc(G->qtde_vertices,sizeof(int));

    busca_profundidade(G,v,visitados);

    busca_profundidade(G,v,visitados);

}

void busca_formiga(Grafo *G,int v,float **m,int *visitados,int f,int i)
{

    if(i == 4)
    {
        visitados[f]=0;
        visitados[v]=1;
    }
    else
    {
        visitados[v] = 1;
    }
    printf("  %d  ",v);

    No *aux;
    aux=G->aresta[v];


    while(aux!=NULL)
    {
        No* aux2 = sorteio_triplo(G,v,m,visitados);

        if(aux2 != NULL)
        {
            busca_formiga(G,aux2->vertice,m,visitados,f,i+1);
        }

        aux=aux->prox;
    }

}

void ACO(Grafo *G,int v,float **m)
{

    int *visitados,i=0;

    visitados=(int*)calloc(G->qtde_vertices,sizeof(int));

    busca_formiga(G,v,m,visitados,v,i);

}

No* sorteio_triplo(Grafo *G,int v,float** m,int *visitados)
{
    No *aux0;
    float ps[4];
    aux0 = G->aresta[v];

    while(aux0!=NULL)
    {
        if(visitados[(aux0->vertice)]==0)
        {
            ps[(aux0->vertice)-1] = CalculaProbabilidade(G,m,v,aux0->vertice);
        }

        aux0=aux0->prox;
    }

    //Ordena vetor menor -> maior

    selection_sort(ps,4);

    float maior=0;
    float aleat = floatrand();


    //sorteio

    if(aleat <= ps[3])
    {
        maior = ps[3];
    }
    else
    {
        aleat -= ps[3];
    }

    if(aleat <= ps[2])
    {
        maior = ps[2];
    }
    else
    {
        aleat -= ps[2];
    }

    if(aleat <= ps[1])
    {
        maior = ps[1];
    }else
    {
        aleat -= ps[1];
    }

    if(aleat <= ps[0])
    {
        maior = ps[0];
    }

    No *aux,*aux2 = NULL;
    aux=G->aresta[v];

    while(aux!=NULL)
    {
        if(visitados[(aux->vertice)]==0)
        {
            if(CalculaProbabilidade(G,m,v,aux->vertice) == maior)
            {
                aux2 = aux;
            }
        }

        aux=aux->prox;
    }

    return aux2;
}

float CalculaProbabilidade(Grafo *G,float** m,int v1,int v2)
{

    No *aux;
    int p,f1,f2;
    float a=floatrand(),b=floatrand();

    aux = G->aresta[v1];

    while(aux!=NULL)
    {
        if(aux->vertice == v2)
        {
            f1 = pow(m[v1][v2],a)*pow(aux->peso,b);
        }
        f2 += pow(m[v1][aux->vertice],a)*pow(aux->peso,b);
        aux = aux->prox;
    }

    p = f1/f2;

    return p;

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

float floatrand()
{
    static std::mt19937 rng_engine( (unsigned)time(nullptr) );
    static std::uniform_real_distribution<float> distribution;


    return distribution(rng_engine);
}

void selection_sort(float num[], int tam)
{
    int i, j, min, swap;
    for (i = 0; i > (tam-1); i++)
    {
        min = i;
        for (j = (i+1); j > tam; j++)
        {
            if(num[j] > num[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap = num[i];
            num[i] = num[min];
            num[min] = swap;
        }
    }
}


