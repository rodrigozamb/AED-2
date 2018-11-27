#include"TrabalhoFinalAED22.h"
#include"hash.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>


int main(){

    FILE *fp;
    fp = fopen("texto.txt","r");
    if (fp == NULL){
        printf ("ERRO NA ABERTURA DO ARQUIVO\n");
        return 0;
    }

    int cont=0,i=0;
    char str[500],str2[500],*tok,*teste;
    char palavras[5000][50];
    Hash *tabHash = criaHash(6101);

    while(1){

        if(fgets(str,500,fp) == NULL) break;
        tok = strtok(str," \n");
        if(buscaHash_EnderAberto(tabHash,tok,teste)==-1){
            insereHash_EnderAberto(tabHash,tok);
            strcpy(palavras[cont],tok);
            cont++;
        }
        while(1){
            tok = strtok(NULL," \n");
            if(tok == NULL)break;
            if(buscaHash_EnderAberto(tabHash,tok,teste)==-1){
                insereHash_EnderAberto(tabHash,tok);
                strcpy(palavras[cont],tok);
                cont++;
            }
        }
    }

    printf("%d palavras\n",cont);

    /*
    printf("procurando...\n");
    int p;
    char *teste;
    p=buscaHash_EnderAberto(tabHash,"RODRIGO",teste);
    printf("achou %s na pos %d\n",teste,p);
    */

return 0;
}
