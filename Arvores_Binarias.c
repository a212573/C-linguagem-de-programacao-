
#include <stdio.h>
#include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct no{
    char chave;
    struct no *dir;
    struct no *esq;
}NO;



void inserir(NO *raiz,NO *p, int ld){

    if(ld==1){ 
        if(raiz->dir == NULL) raiz->dir = p;
        else inserir(raiz->dir,p,ld);
    }
    if(ld==0){
        if(raiz->esq == NULL) raiz->esq = p;
        else inserir(raiz->esq,p,ld);
    }
}

void imprimePosOrdem(NO *raiz){ 
    if(raiz->esq != NULL) imprimePosOrdem(raiz->esq);
    if(raiz->dir != NULL) imprimePosOrdem(raiz->dir);
    printf("%c ",raiz->chave);
    free(raiz);
}



int nula(NO* raiz){ // verifica se árvore está vazia
    if(raiz == NULL) 
        return 1; // true para nulo 
    else 
        return 0;
}




int main()
{
    
    NO *raiz;   
    raiz = NULL;
    NO *p;

    
    int i, j, k, m;
    int tamanho;
    scanf( "%d\n", &tamanho );
    char vet1[tamanho];
    

    for( i=0;i<tamanho-1;i++){
        scanf( "%c ", &vet1[i] );
    }
    scanf( "%c\n", &vet1[tamanho-1] );
    char vet2[tamanho];
    for( i=0;i<tamanho-1;i++){
        scanf( "%c ", &vet2[i] );
    }
    scanf( "%c", &vet2[tamanho-1] );



    




    if(nula(raiz)) {
        p=(NO*) malloc(sizeof(NO)); 
        p->chave=vet1[0];
        p->dir = NULL;
        p->esq = NULL;
        raiz = p;
    }
    
    int foi_inserido[tamanho];
    for( i=0;i<tamanho;i++){
        foi_inserido[i]=0;
    }
    foi_inserido[0]=1;
    //no=vet1;
    
    for( i=0;i<tamanho;i++){
        for( j=1;j<tamanho;j++)
        {
            
            if (vet2[j]==vet1[i])
            {
                for( k=i+1;k<tamanho;k++)
                {         
                    if (foi_inserido[k]==0){
                        for( m=0;m<tamanho;m++)
                        {
                            if (vet2[m]==vet1[k])
                            {
                                if (m<j)
                                {
                                    //inserir vet k a esquerda de vet i
                                    p=(NO*) malloc(sizeof(NO)); 
                                    p->chave=vet1[k];
                                    p->dir = NULL;
                                    p->esq = NULL;
                                    
                                        inserir(raiz,p,0);
                                        foi_inserido[k]=1;
                                    
                                    
                                        

                                }
                                if (m>j)
                                {
                                    //inserir vet k a direita de vet i
                                    p=(NO*) malloc(sizeof(NO)); 
                                    p->chave=vet1[k];
                                    p->dir = NULL;
                                    p->esq = NULL;
                                     
                                    
                                        inserir(raiz,p,1);
                                        foi_inserido[k]=1;
                                    
                                   
                                }
                            }
                        }
                    }
                    
                        
                }
            }
        }

    }

    imprimePosOrdem(raiz);
    printf("\n");
    
    return 0;
}