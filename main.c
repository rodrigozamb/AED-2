#include"TrabalhoFinalAED22.h"
#include"hash.h"
#include"hash.c"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>


int main(){

    FILE *fp;
    fp = fopen("texto_base.txt","r");
    if (fp == NULL){
        printf ("ERRO NA ABERTURA DO ARQUIVO\n");
        return 0;
    }

    int cont=0,i=0;
    char str[500],str2[500],*tok,*teste;
    char palavras[5000][50],iniciais[5000][50];
    Hash *tabHash = criaHash(6101);

    while(1){

        if(fgets(str,500,fp) == NULL) break;
        tok = strtok(str," \n");
        if(buscaHash_EnderAberto(tabHash,tok,teste)==-1){
            insereHash_EnderAberto(tabHash,tok);
            strcpy(palavras[cont],tok);
            if(tok[0]>='A' && tok[0]<='Z')strcpy(iniciais[cont],tok);
            else strcpy(iniciais[cont],"n");
            cont++;
        }
        while(1){
            tok = strtok(NULL," \n");
            if(tok == NULL)break;
            if(buscaHash_EnderAberto(tabHash,tok,teste)==-1){
                insereHash_EnderAberto(tabHash,tok);
                strcpy(palavras[cont],tok);
                if(tok[0]>='A' && tok[0]<='Z')strcpy(iniciais[cont],tok);
                else strcpy(iniciais[cont],"n");
                cont++;
            }
        }
    }

    printf("%d palavras\n",cont);

    printf("Lista de palavras e seus nums representantes : \n");
    for(i=0;i<cont;i++){
        if(strcmp(iniciais[i],"n")!=0)printf("%s - [%d]\n",iniciais[i],i);
    }



    /*
    printf("procurando...\n");
    int p;
    char *teste;
    p=buscaHash_EnderAberto(tabHash,"RODRIGO",teste);
    printf("achou %s na pos %d\n",teste,p);
    */

return 0;
}
