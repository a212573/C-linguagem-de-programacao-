#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int num;
   struct no *esq;
   struct no *dir;
   
}No;


typedef struct arvore {
   No *raiz;
}Arvore;


No* cria_no(int num);
Arvore* cria_arvore(int num);
No* acha_menor(No *tree);
void insere_no(No *tree, int num);
void insere_no_1(No *tree, int num);
No *remove_no(No *tree, int num);

No* cria_no(int num){
	No *tree;
	tree = (No*) malloc(sizeof(No));
	
	tree->esq = NULL;
	tree->dir = NULL;
	tree->num = num;
	
	return tree;
}

Arvore* cria_arvore(int num){
	Arvore *tree;
	tree = (Arvore*) malloc(sizeof(Arvore));
	tree->raiz = cria_no(num);
	
	return tree;
}



No* acha_menor(No *tree) {
	if(tree->esq == NULL) {
		return tree;
	}
	return acha_menor(tree->esq);
}

void insere_no(No *tree, int num) {
	if(num < tree->num) { /* num menor */
		if(tree->esq) {
			insere_no(tree->esq, num);
		} else { /* achou local de inserção */
			No *novo = cria_no(num);
			tree->esq = novo;
		}
	} else { /* num maior ou igual ao nodo atual */
		if(tree->dir) {
			insere_no(tree->dir, num);
		} else {
			No *novo = cria_no(num);
			tree->dir = novo;
		}
	}
}

void insere_no_1(No *tree, int num){
	int ins=1;
	while(ins!=0){
	if(num > tree->num ||num == tree->num){
		if(tree->dir==NULL){
		No *novo = cria_no(num);
		tree->dir = novo;
		ins=0;
		}else{
		tree = tree->dir;
		}
	}else{
		if(tree->esq==NULL){
		No *novo = cria_no(num);
		tree->esq = novo;
		ins=0;
		}else{
		tree = tree->esq;
		}
	}
	}
}

No *remove_no(No *tree, int num){
	No *aux;
	
	if(tree == NULL) {
	} else if(num < tree->num){
		tree->esq = remove_no(tree->esq, num);	
	} else if(num > tree->num){
		tree->dir = remove_no(tree->dir, num);	
	} else if(tree->esq == NULL && tree->dir == NULL) {
		free(tree);
		return NULL; /* zero filhos */
	} else if(tree->esq == NULL) {
		aux = tree->dir;
		free(tree);
		return aux; /* 1 filho direita */
	} else if(tree->dir == NULL) {
		aux = tree->esq;
		free(tree);
		return aux; /* 1 filho esquerda */
	} else { /* 2 filhos */
		No *menor = acha_menor(tree->dir);
		tree->num = menor->num;
		tree->dir = remove_no(tree->dir, menor->num);
		return tree;
	}
	
	return tree;
	
}

                                   

void exibirPreOrdem (No *raiz)
{
	if(raiz != NULL)
	{
        if (raiz->num!=-14444){
            printf("%d ", raiz->num);
        }
		exibirPreOrdem(raiz->esq);
		exibirPreOrdem(raiz->dir);
	}
}

void exibirInOrdem (No *raiz)
{
	if(raiz != NULL)
	{
		exibirInOrdem(raiz->esq);
		if (raiz->num!=-14444){
            printf("%d ", raiz->num);
        }
		exibirInOrdem(raiz->dir);
	}
}

void exibirPosOrdem (No *raiz)
{
	if(raiz != NULL)
	{
		exibirPosOrdem(raiz->esq);
		exibirPosOrdem(raiz->dir);
		if (raiz->num!=-14444){
            printf("%d ", raiz->num);
        }
	}
}

void limpar(No *tree){
	No *esquerda;
	No *direita;
	while(tree->esq!=NULL){
	esquerda = tree->esq;
	remove_no(tree,esquerda->num);
	}
	while(tree->dir!=NULL){
	direita = tree->dir;
	remove_no(tree,direita->num);
	}
	free(tree);
}


int vazia(No *raiz)
{
    int i=0;
	if(raiz != NULL && raiz->num==-14444 && raiz->dir==NULL)
	{
		i=1;
	}
    return i;
}



int main(){
    Arvore *tree;
    char *c;
    c=malloc(1);
    int i;
    scanf("%c",&*c);
    if (*c!='F'){
        scanf("%d",&i);
        if (*c=='I') {
            tree = cria_arvore(-14444);
            insere_no_1(tree->raiz,i);
        }
        if (*c=='R'){
            while (1>0){
                scanf("%c",&*c);
                if (*c=='F'){
                    break;
                } 
                scanf("%d",&i);
                if (*c=='I'){
                    tree = cria_arvore(-14444);
                    insere_no_1(tree->raiz,i);
                    break;
                } 
            }
        }
        if (*c!='F'){
            while (1>0){
                scanf("%c",&*c);
                if (*c=='F'){
                    break;
                } 
                scanf("%d",&i);
                if (*c=='I'){
                    insere_no_1(tree->raiz,i);
                } 
                if (*c=='R'){
                   remove_no(tree->raiz, i);
                } 


            }
        }
    }
	else{
		tree = cria_arvore(-14444);
	}
    

    if(vazia(tree->raiz)==1){
        printf("ARVORE RESULTANTE VAZIA\n");
    }
    if(vazia(tree->raiz)==0){
          exibirPreOrdem(tree->raiz);
          printf("\n");
          exibirInOrdem(tree->raiz);
          printf("\n");
          exibirPosOrdem(tree->raiz);
          printf("\n");
    }
      



    
    free(c);
    limpar(tree->raiz);
    free(tree);

	return 0;
}