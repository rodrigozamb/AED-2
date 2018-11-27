#ifndef TRABALHOFINALAED22_H_INCLUDED
#define TRABALHOFINALAED22_H_INCLUDED


struct no{
    int vertice;
    char palavra[30];
    struct no *prox;
};
typedef struct no No;

struct grafo{
    int qtde_vertices;
    int *grau;
    No**aresta;
};

typedef struct grafo Grafo;

Grafo *cria_grafo(int vert);
void mostra_grafo(Grafo *G);
int verifica_aresta(Grafo *G,int v1,int v2);
int remove_arestaN(Grafo *G,int v1,int v2);
int consulta_aresta(Grafo *G,int v1,int v2,float *peso);
void libera_grafo(Grafo **G);
void mostra_adjacentes(Grafo *G,int v);
void busca_profundidade(Grafo *G,int v,int *visitados);
void DPS(Grafo *G,int v);
float** CriarMatriz(int Linhas,int Colunas);
void mostraMatriz(float** m,int Linhas,int Colunas);
void InserirMatriz(float** m,int v1,int v2,float feromonio,int tam);
void RemoverMatriz(float** m,int v1,int v2,int tam);
float CalculaProbabilidade(Grafo *G,float** m,int v1,int v2);
void ACO(Grafo *G,int v,float **m);
void busca_formiga(Grafo *G,int v,float **m,int *visitados,int f,int i);
float floatrand();
No* sorteio_triplo(Grafo *G,int v,float** m,int *visitados);
void selection_sort(float num[], int tam);




#endif // TRABALHOFINALAED22_H_INCLUDED
