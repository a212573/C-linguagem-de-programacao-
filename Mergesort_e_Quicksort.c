#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct {
    int chave;
}Item;

int Nchaves;
typedef struct {
    Item *v;
    int n , tamanho;
}FP;

typedef FP *p_fp;

int K;

void bubblesort (p_fp fprio , int l, int r);
int partition ( p_fp fprio , int l , int r);
p_fp criar_filaprio(int tam) ;
void insere ( p_fp fprio , Item item );
  
void insere ( p_fp fprio , Item item ) {
    fprio ->v[ fprio -> n] = item ;
    fprio ->n ++;
}
void troca ( Item *a , Item *b) {
    Item t=*a;
    *a=*b;
    *b=t;
}

void merge ( p_fp fprio , int l , int m , int r) {
    int aux [Nchaves+5];
    int i = l , j = m + 1, k = 0;
    /* intercala */
    while (i <= m && j <= r)
        if (fprio->v[i].chave <=fprio->v[j].chave)
            aux [k++] = fprio->v[i++].chave;
        else
            aux [k++] =fprio->v[j++].chave;
        /* copia o resto do subvetor que não terminou */
    while (i <= m)
        aux [k++] = fprio->v[i++].chave;
    while (j <= r)
        aux[k++] = fprio->v[j++].chave;
    /* copia de volta para v*/
    for (i = l , k = 0; i <= r; i ++ , k ++)
        fprio->v[i].chave = aux [k ];
}


void mergesort ( p_fp fprio , int l , int r) {
    int m = (l + r) / 2;
    for (int i = 0; i < Nchaves ; i++) {
        printf("%d ",fprio ->v[i].chave);

    }
    printf("\n");
    if (l < r && r-l>K) {
        /* divisão*/
        mergesort (fprio , l , m );
        mergesort (fprio , m + 1, r);
        /* conquista */
        merge (fprio , l , m , r);
        
    }
    
    if (l < r && r-l<=K) {
        bubblesort(fprio, l, r);
    }
    
    

    
}

void quicksort ( p_fp fprio , int l , int r) {
    int i;
    for (int i = 0; i < Nchaves ; i++) {
        printf("%d ",fprio ->v[i].chave);

    }
    printf("\n");
    if (r <= l) return ;
    if (l < r && r-l>K) {
        i = partition (fprio , l , r );
        quicksort (fprio , l , i -1) ;
        quicksort (fprio , i +1 , r);
    }
    if (l < r && r-l<=K) {
        bubblesort(fprio, l, r);
    }
    
    
    
}
    

int partition ( p_fp fprio , int l , int r) {
    int i , pivo = fprio ->v[l].chave, pos = r + 1;
    int t;
    for (i = r; i >= l; i--) {
        if (fprio ->v[i].chave >= pivo ) {
            pos--;
            t=fprio ->v[i].chave;
            fprio ->v[i].chave=fprio ->v[pos].chave;
            fprio ->v[pos].chave=t;
        }
    }
    return pos ;
}        

void bubblesort (p_fp fprio , int l, int r) {
    int i , j, t;
    int n = r+1;
    for (i = l; i < n - 1; i ++)
        for (j = n - 1; j > i; j--)
            if (fprio ->v[j].chave < fprio ->v[j-1].chave)
            {
                t=fprio ->v[j-1].chave;
                fprio ->v[j-1].chave=fprio ->v[j].chave;
                fprio ->v[j].chave=t;
                
            }
                
}

void bubblesort_v2 (p_fp fprio , int l, int r) {
    int i , j , t , trocou = 1;
    int n = r+1;
    for (i = l; i < n - 1 && trocou ; i++) {
        trocou = 0;
        for (j = n - 1; j > i; j--)
            if (fprio ->v[j].chave <fprio ->v[j-1].chave) {
                t=fprio ->v[j-1].chave;
                fprio ->v[j-1].chave=fprio ->v[j].chave;
                fprio ->v[j].chave=t;
                trocou = 1;
            }
    }
}
    






p_fp criar_filaprio ( int tam ) {
    p_fp fprio = malloc ( sizeof ( FP ));
    fprio->v = malloc ( tam * sizeof ( Item ));
    fprio->n = 0;
    fprio->tamanho=tam ;
    return fprio ;
}




p_fp deleta( p_fp fprio) {
    free(fprio->v);
    free(fprio);
    
    return 0;
}




int main() {
    int i;
    scanf("%d\n", &Nchaves);
    int chaves[Nchaves];
  


    for(i = 0; i<Nchaves-1; i++){
        scanf("%d ",&chaves[i]);
    }
    scanf("%d\n",&chaves[Nchaves-1]);
    scanf("%d",&K);



    Item *item;
    item=NULL;
    item = (Item *)malloc(sizeof(Item));
    p_fp fprio=criar_filaprio ( Nchaves+5 );
    p_fp fprio2=criar_filaprio ( Nchaves+5 );


    for(i = 0; i<Nchaves; i++){
        item->chave=chaves[i];
        insere (fprio , *item);
    }
    for(i = 0; i<Nchaves; i++){
        item->chave=chaves[i];
        insere (fprio2 , *item);
    }
    printf("MERGESORT\n");
    mergesort (fprio, 0 , Nchaves-1);
    for (int i = 0; i < Nchaves ; i++) {
        printf("%d ",fprio ->v[i].chave);

    }
    printf("\n");


    printf("QUICKSORT\n");
    quicksort (fprio2, 0 , Nchaves-1);
    for (int i = 0; i < Nchaves ; i++) {
        printf("%d ",fprio ->v[i].chave);

    }
    printf("\n");
    

    


        
       
    

    

    

    deleta(fprio);
    deleta(fprio2);
    free(item);
    return 0;
}