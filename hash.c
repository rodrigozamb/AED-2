//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h" //inclui os Protótipos

//Definição do tipo Hash
struct hash{
    int qtd, TABLE_SIZE;
    char **itens;
};

Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (char**) malloc(TABLE_SIZE * sizeof(char*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

//==============================================
int valorString(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return (valor & 0x7FFFFFFF);
}

//Hash Divisao
//int chave = valorString(nome);
//pos = chaveDivisao(chave, TABLE_SIZE)
int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}


//==============================================
// Insere e busca comcom tratamento de colisão: Endereçamento Aberto
//==============================================
int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2*i + 5*i*i;// hash + (c1 * i) + (c2 * i^2)
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}


int insereHash_EnderAberto(Hash* ha, char *palavra){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    //int chave = al.matricula;
    int chave = valorString(palavra);

    int i, pos, newPos;
    pos = chaveDivisao(chave,ha->TABLE_SIZE);

    for(i=0; i < ha->TABLE_SIZE; i++){
        //newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
        newPos = sondagemQuadratica(pos,i,ha->TABLE_SIZE);
        //newPos = duploHash(pos,chave,i,ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){

            char * novo = (char*) malloc(strlen(palavra)*sizeof(char));
            if(novo == NULL)
                return 0;
            strcpy(novo,palavra);

            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int buscaHash_EnderAberto(Hash* ha, char *palavraEsp, char* palavra){
    if(ha == NULL)
        return -1;

    int i, pos, newPos;
    int chave = valorString(palavraEsp);
    pos = chaveDivisao(chave,ha->TABLE_SIZE);
    for(i=0; i < ha->TABLE_SIZE; i++){
        //newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
        newPos = sondagemQuadratica(pos,i,ha->TABLE_SIZE);
        //newPos = duploHash(pos,mat,i,ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL)
            return -1;

        if(strcmp(palavraEsp,ha->itens[newPos])==0){
            strcpy(palavra,ha->itens[newPos]);
            printf("pos = %d\n",pos);
            return pos;
        }
    }
    return -1;
}
