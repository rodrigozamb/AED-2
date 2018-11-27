#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);

int insereHash_SemColisao(Hash* ha, struct aluno al);

int chaveDivisao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int sondagemLinear(int pos, int i, int TABLE_SIZE);
int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
int duploHashing(int pos, int chave, int i, int TABLE_SIZE);
int buscaHash_EnderAberto(Hash* ha, char *palavraEsp, char* palavra);

#endif // HASH_H_INCLUDED
