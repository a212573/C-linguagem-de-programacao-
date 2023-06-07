#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
# define PAI(i) ((i -1) /2)

typedef struct {
    int chave;
}Item;

typedef struct {
    Item *v;
    int n , tamanho;
}FP;

typedef FP *p_fp;

p_fp criar_filaprio(int tam) ;
void insere ( p_fp fprio , Item item );
Item extrai_maximo ( p_fp fprio );
int vazia ( p_fp fprio );
int cheia ( p_fp fprio );    

void troca ( Item *a , Item *b) {
    Item t=*a;
    *a=*b;
    *b=t;
}


p_fp criar_filaprio ( int tam ) {
    p_fp fprio = malloc ( sizeof ( FP ));
    fprio->v = malloc ( tam * sizeof ( Item ));
    fprio->n = 0;
    fprio->tamanho=tam ;
    return fprio ;
}



void sobe_no_heap ( p_fp fprio , int k ) {
    if (k > 0 && fprio->v[ PAI (k) ]. chave < fprio -> v[k ]. chave ) {
        troca (& fprio->v[k], & fprio -> v[ PAI (k) ]) ;
        sobe_no_heap ( fprio , PAI (k ));
    }
}

void insere ( p_fp fprio , Item item ) {
    fprio ->v[ fprio -> n] = item ;
    fprio ->n ++;
    sobe_no_heap ( fprio , fprio ->n - 1) ;
}


Item extrai_maximo ( p_fp fprio ) {
    int j , max = 0;
    for (j = 1; j < fprio ->n; j ++)
        if ( fprio ->v[ max ]. chave < fprio ->v[j ]. chave )
            max = j;
    troca (&( fprio ->v[ max ]) , &( fprio ->v[ fprio ->n -1]) );
    fprio ->n--;
    return fprio ->v[ fprio ->n ];
}

int e[100][100];
int t1[100];

void escreve( p_fp fprio, int lin) {

    int col = t1[lin];
    int k;
    int k1;
    int k2;
    int i;
    int i1;
    int i2;
    if (t1[lin]<t1[lin-1]){
        fprio ->v[col+1]. chave=fprio ->v[0]. chave;
        fprio ->v[0]. chave=0;

        for (i=0; i<col+1 ; i++){
            if (fprio ->v[i].chave==0){
                i1=2*i +1;
                i2=2*i +2;
                k1=0;
                k2=0;
                if (i1> col && i2>col){
                   fprio ->v[i].chave=fprio ->v[col+1]. chave;
                   fprio ->v[col+1]. chave=0;
                } 
                else{
                    if (fprio ->v[col+1].chave>fprio ->v[i1].chave && fprio ->v[col+1].chave>fprio ->v[i2].chave){
                        fprio ->v[i].chave=fprio ->v[col+1]. chave;
                        fprio ->v[col+1].chave=0;
                        k1=1;
                    }
                    if (fprio ->v[i1].chave>fprio ->v[i2].chave && k1==0){
                        fprio ->v[i].chave=fprio ->v[i1]. chave;
                        fprio ->v[i1].chave=0;
                        k2=1;
                    }
                    if (fprio ->v[i2].chave>fprio ->v[i1].chave && k1==0 && k2==0) {
                        fprio ->v[i].chave=fprio ->v[i2]. chave;
                        fprio ->v[i2].chave=0;
                    }
                    

                }

            }

        }

        for (i=0; i<col+1 ; i++){
            if (2*i+2<=col){
                if (fprio ->v[2*i+2].chave>fprio ->v[i].chave){
                    k=fprio ->v[2*i+2].chave;
                    fprio ->v[2*i+2].chave=fprio ->v[i].chave;
                   fprio ->v[i].chave=k;
                }
            }

        }
        
    }


    
    
    
    
    for (i=0; i<col+1 ; i++){
        e[lin][i]=fprio ->v[i]. chave;

    }
    
    
}

p_fp deleta( p_fp fprio) {
    free(fprio->v);
    free(fprio);
    
    return 0;
}




int main() {
    char *c;
    c = (char *)malloc(sizeof(char));
    int i;
    Item *item;
    item=NULL;
    item = (Item *)malloc(sizeof(Item));
    int t2=-1;
    int t3=-1;

    p_fp fprio=criar_filaprio ( 100 );

    while (1>0){
        scanf("%c",&*c);
        t2=t2+1;
        if (*c=='F' && t2==0){
            printf("VAZIO\n");
        }


        
        
        if (*c=='I'){
            scanf(" %d\n",&i);
            if (t2<=99){
                item->chave=i;
                insere (fprio , *item);
                t3=t3+1;

            }
            
            
        }
        if (*c=='M'){
            if (t2<=99){
                extrai_maximo(fprio);
                t3=t3-1;

            }
            
            scanf("\n");
        }
        if (t2<=99){
            t1[t2]=t3;
            escreve(fprio,t2);
        }
        
        if (*c=='F') break;
        
        
    }

    int j;
    for (i=0; i<t2 ; i++){
        if (e[i][0]==0 && e[i][1]==0 && e[i][2]==0){
            printf("VAZIO\n");
        }
        else{
            for (j=0; j<t1[i]+1 ; j++){
                printf("%d ",e[i][j]);
            }
            printf("\n");
        }
        
    }

    

    free(c);
    deleta(fprio);
    free(item);
    return 0;
}
