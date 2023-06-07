#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    long long int chave;
}Item;

typedef struct {
    Item *v;
    int n , tamanho;
}FP;

typedef FP *p_fp;

p_fp criar_filaprio(int tam) ;
void insere ( p_fp fprio , Item item );
Item extrai( p_fp fprio , long long int x , int tam);

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



void insere ( p_fp fprio , Item item ) {
    fprio->v[ fprio->n] = item ;
    fprio ->n ++;
}


Item extrai( p_fp fprio , long long int x, int tam ) {
    int j;
    for (j=0; j<tam +1 ; j++)
        if ( fprio->v[j]. chave == x) fprio ->v[j].chave = 0;
    fprio->n--;
    return fprio ->v[ fprio ->n ];
}




void escreve( p_fp fprio, int tam , long long int v_resultante[100]) {

    int i;
  
    for (i=0; i<tam +1 ; i++){
        v_resultante[i]=fprio ->v[i]. chave;

    }
    
    
}



p_fp deleta( p_fp fprio) {
    free(fprio->v);
    free(fprio);
    
    return 0;
}

void dummy(int M, int N, long long int v_dummy[M], long long int f_hash[N], long long int v_resultante[100]){
    int i, j, k1, k2;
    for (i=0; i<N ;i++){
        k1=0;
        if (v_dummy[f_hash[i]]==-1){
            v_dummy[f_hash[i]]=v_resultante[i];
            k1=1;

        }
            
        if (v_dummy[f_hash[i]]!=-1 && k1==0){
            k2=0;
            for (j=f_hash[i]; j<M ; j++){
                if (v_dummy[j]==-1){
                    k2=1;
                    v_dummy[j]=v_resultante[i];
                    break;
                }

            }
            if (k2==0){
                for (j=0; j<M ; j++){
                    if (v_dummy[j]==-1){
                        v_dummy[j]=v_resultante[i];
                        break;
                    }

                }

            }
        }
    }
}


void rehash(int M, int N, long long int v_rehash[M], long long int f_hash[N], long long int v_resultante[100]){
    int i, j, k1;
    for (i=0; i<M ;i++){
        k1=i;
        for (j=0; j<N ; j++){
            if (f_hash[j]==i && v_rehash[k1]==0){
                v_rehash[k1]=v_resultante[j];
                k1=k1+1;
            }
            
        }
    }
}


int main()
{
    long long int v_resultante[100];
    Item *item;
    item=NULL;
    item = (Item *)malloc(sizeof(Item));
    
    p_fp fprio=criar_filaprio ( 100 );

    int i, j, M, P, A, B, N, K;
    scanf("%d ", &M);
    scanf("%d ", &P);
    scanf("%d ", &A);
    scanf("%d\n", &B);
    scanf("%d\n", &N);

    char char_inseridos[N][20];
    long long int num_inseridos[N];
    long long int f_hash[N];
    
    for (i=0; i<N-1 ;i++){
        scanf( "%s ",  char_inseridos[i]);
    }
    scanf( "%s\n",  char_inseridos[N-1]);
    scanf("%d\n", &K);

    char num_removidos[N][20];
    long long int LN2[N];
    
    for (i=0; i<K-1 ;i++){
        scanf( "%s ",  num_removidos[i]);

    }
    scanf( "%s",  num_removidos[K-1]);


    long long int *c;
    c = (long long int *)malloc(sizeof(long int));
    long long int t;
    long long int k1;
    long long int k2;

    for (i=0; i<N ;i++){
        num_inseridos[i]=0;
    }
    for (i=0; i<N ;i++){
        for (j=0; j<20 ;j++){
            *c=char_inseridos[i][j];
            if (*c=='\0'){
                t=j-1;
                break; 
            } 


        }
        for (j=0; j<t+1 ;j++){
            *c=char_inseridos[i][j];
            
            k1=t-j;
            k2=pow(256,k1);
            

            num_inseridos[i]=num_inseridos[i] + (*c  * k2);
            

        }

    }


    for (i=0; i<K ;i++){
        LN2[i]=0;
    }
    for (i=0; i<K ;i++){
        for (j=0; j<20 ;j++){
            *c=num_removidos[i][j];
            if (*c=='\0'){
                t=j-1;
                break; 
            } 


        }
        for (j=0; j<t+1 ;j++){
            *c=num_removidos[i][j];
            
            k1=t-j;
            k2=pow(256,k1);
            

            LN2[i]=LN2[i] + (*c  * k2);

        }
        

    }

    for (i=0; i<N ;i++){
        f_hash[i]=((A*num_inseridos[i]+B) % P) % M;
        item->chave=num_inseridos[i];
        insere (fprio , *item);
    }
    for (i=0; i<K ;i++){
        extrai(fprio ,LN2[i], N);
    }


    escreve(fprio ,N, v_resultante);

    long long int v_dummy[M];

    for (i=0; i<M ;i++){
        v_dummy[i]=-1;
    }
    
    dummy(M, N, v_dummy, f_hash, v_resultante);



    long long int v_rehash[M];

    for (i=0; i<M ;i++){
        v_rehash[i]=0;
    }
    
    rehash(M, N, v_rehash, f_hash, v_resultante);


    
    printf("---------------------------------------------\n rehash               | dummy\n---------------------------------------------\n");
    
    long long int numero;
    int digitos;
    
    for (i=0; i< M; i++){
        if (v_rehash[i]==0 && v_dummy[i]==-1){
            printf(" VAZIO                | VAZIO                \n");
        }
        if (v_rehash[i]==0 && v_dummy[i]==0){
            printf(" VAZIO                | DUMMY               \n");
        }
        if (v_rehash[i]!=0 && v_dummy[i]!=-1 && v_dummy[i]!=0 ){
            printf(" %lld",v_rehash[i]);

            numero=v_rehash[i];
            digitos=0;
            while (numero>0){
                digitos=digitos+1;
                if (numero<10) break;
                numero=floor(numero/10);
            } 
            for (j=0; j< 20-digitos ; j++) printf(" ");

            printf(" | %lld",v_dummy[i]);

            numero=v_dummy[i];
            digitos=0;
            while (numero>0){
                digitos=digitos+1;
                if (numero<10) break;
                numero=floor(numero/10);
            } 
            for (j=0; j< 20-digitos ; j++) printf(" ");

            printf(" \n");

        } 
        if (v_rehash[i]==0 && v_dummy[i]!=-1 && v_dummy[i]!=0){
            printf(" VAZIO                | ");

            printf("%lld",v_dummy[i]);

            numero=v_dummy[i];
            digitos=0;
            while (numero>0){
                digitos=digitos+1;
                if (numero<10) break;
                numero=floor(numero/10);
            } 
            for (j=0; j< 20-digitos ; j++) printf(" ");

            printf(" \n");

        } 
        if (v_rehash[i]!=0 && v_dummy[i]==-1){
            printf(" %lld",v_rehash[i]);

            numero=v_rehash[i];
            digitos=0;
            while (numero>0){
                digitos=digitos+1;
                if (numero<10) break;
                numero=floor(numero/10);
            } 
            for (j=0; j< 20-digitos ; j++) printf(" ");

            printf(" | VAZIO                \n");

        } 
        if (v_rehash[i]!=0 && v_dummy[i]==0){
            printf(" %lld",v_rehash[i]);

            numero=v_rehash[i];
            digitos=0;
            while (numero>0){
                digitos=digitos+1;
                if (numero<10) break;
                numero=floor(numero/10);
            } 
            for (j=0; j< 20-digitos ; j++) printf(" ");

            printf(" | DUMMY                \n");

        }
    }
    
    

    
    deleta(fprio);
    free(c);
    free(item);


    return 0;



}