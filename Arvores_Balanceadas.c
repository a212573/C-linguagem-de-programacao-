#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _NO
{
  int chave;
  char cor;
  struct _NO *dir;
  struct _NO *esq;
} NO;

int K;
int alt_max;

void insereLLRN(NO **ptraiz, int chave);
void insere(NO **ptraiz, int chave);
void rotesq(NO **ptraiz);
void rotdir(NO **ptraiz);
int altura(NO *ptraiz);
int teto(NO *ptraiz);
int piso(NO *ptraiz);
char cor(NO *pt);
void imprimePreOrdem(NO *ptraiz);
void deleta(NO *ptraiz);

int main() {
  int Nchaves, i;
  NO *ptraiz = NULL;
  scanf("%d\n", &Nchaves);
  int chaves[Nchaves];
  


  for(i = 0; i<Nchaves-1; i++){
    scanf("%d ",&chaves[i]);
  }
  scanf("%d\n",&chaves[Nchaves-1]);
  scanf("%d",&K);
  for(i = 0; i<Nchaves; i++){
    insere(&ptraiz,chaves[i]);
  }
  alt_max=altura(ptraiz);
  imprimePreOrdem(ptraiz);
  printf("%d\n",teto(ptraiz));
  printf("%d\n",piso(ptraiz));
  deleta(ptraiz);

  return 0;
}


void insere(NO **ptraiz, int chave){
  insereLLRN(ptraiz, chave);
  (*ptraiz)->cor = 'N';
}

void insereLLRN(NO **ptraiz, int chave){
  if(*ptraiz == NULL){
    *ptraiz = (NO*) malloc(sizeof(NO*));
    (*ptraiz)->chave = chave;
    (*ptraiz)->dir = (*ptraiz)->esq = NULL;
    (*ptraiz)->cor = 'R';
    return;
  }
  if(chave < (*ptraiz)->chave){
    insereLLRN(&(*ptraiz)->esq, chave);
  }else{
    insereLLRN(&(*ptraiz)->dir, chave);
  }
  if((cor((*ptraiz)->esq) == 'N') && (cor((*ptraiz)->dir) == 'R')){
    rotesq(ptraiz);
  }
  if((cor((*ptraiz)->esq) == 'R') && (cor(((*ptraiz)->esq)->esq) == 'R')){
    rotdir(ptraiz);
  }
  if((cor((*ptraiz)->esq) == 'R') && (cor((*ptraiz)->dir) == 'R')){
    (*ptraiz)->cor = 'R';
    ((*ptraiz)->esq)->cor = 'N';
    ((*ptraiz)->dir)->cor = 'N';
  }
}

char cor(NO *pt){
  return (pt == NULL)?'N':pt->cor;
}

void rotesq(NO **ptraiz){
  NO *temp;
  char aux;
  aux = (*ptraiz)->cor;
  (*ptraiz)->cor = 'R';
  temp = *ptraiz;
  *ptraiz = temp->dir;
  (*ptraiz)->cor = aux;
  temp->dir = (*ptraiz)->esq;
  (*ptraiz)->esq = temp;
}

void rotdir(NO **ptraiz){
  NO *temp;
  char aux;
  aux = (*ptraiz)->cor;
  (*ptraiz)->cor = 'R';
  temp = *ptraiz;
  *ptraiz = temp->esq;
  (*ptraiz)->cor = aux;
   temp->esq = (*ptraiz)->dir;
   (*ptraiz)->dir =  temp;
}



int altura(NO *ptraiz) {

    int u, v;
    if (ptraiz == NULL) return 0;
    u = altura(ptraiz->esq);
    v = altura(ptraiz->dir);
    if (u > v && ptraiz->cor=='N') return u+1;
    if (v<=u && ptraiz->cor=='N') return v+1;
    if (u > v && ptraiz->cor=='R') return u;
    if (v<=u && ptraiz->cor=='R') return v;

    return 0;
}


void imprimePreOrdem(NO *ptraiz){
  if(ptraiz != NULL){
    printf("%d", ptraiz->chave);
    if (ptraiz->cor=='N') printf(" PRETO %d %d\n",altura(ptraiz),alt_max-altura(ptraiz));
    if (ptraiz->cor=='R') printf(" VERMELHO %d %d\n",altura(ptraiz),alt_max-altura(ptraiz));

    imprimePreOrdem(ptraiz->esq);
    imprimePreOrdem(ptraiz->dir);
  }
}


int teto_m=1000;
int teto_d;
int teto_i;
int teto_f=-1;
int teto(NO *ptraiz){
  if(ptraiz != NULL){
    if (ptraiz->chave >= K ){
      teto_i=ptraiz->chave;
      teto_d=teto_i - K;
      if (teto_d<teto_m){
        teto_m=teto_d;
        teto_f=teto_i;
      }

    } 
    teto(ptraiz->esq);
    teto(ptraiz->dir);
  }
  return teto_f;
}

int piso_m=1000;
int piso_d;
int piso_i;
int piso_f=-1;
int piso(NO *ptraiz){
  if(ptraiz != NULL){
    if (ptraiz->chave <= K ){
      piso_i=ptraiz->chave;
      piso_d=K-piso_i;
      if (piso_d<piso_m){
        piso_m=piso_d;
        piso_f=piso_i;
      }

    } 
    piso(ptraiz->esq);
    piso(ptraiz->dir);
  }
  return piso_f;
}


void deleta(NO *ptraiz){ 
  if(ptraiz != NULL){
    
    deleta(ptraiz->esq);
    deleta(ptraiz->dir);
    free(ptraiz);
    
  }
}



