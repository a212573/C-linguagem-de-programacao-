# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct _Pilha
{
    char op;
    struct _Pilha *prox;

}Pilha;


void transfereTempPos( Pilha **pPos, Pilha **pTemp, Pilha *aux )
{
    aux = ( *pTemp ) -> prox;
    ( *pTemp ) -> prox = *pPos;
    *pPos = *pTemp;
    *pTemp = aux;
}

void alocaCharNaPilha( Pilha **pilha, Pilha *aux, char op )
{
    aux = ( Pilha *) malloc( sizeof( Pilha ) ); 
    aux -> op = op;  
    aux -> prox = *pilha;
    *pilha = aux;
}

int leOperacao( Pilha **pPos, Pilha **pTemp )
{
    int div_zero;
    div_zero=0;
    char op;
    char a;
    a='0';
    Pilha *aux;
    scanf( "%c", &op );
    int k;
    k=-1;
    while( op != '\n' )
    {     
        if ( op != ' ' )
        {
            k=k+1;
            

            switch( op )
            {
                case '+':
                case '-':
    
                    while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                    {
                        transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                    }
    
                    alocaCharNaPilha( &( *pTemp ), aux, op );
                    
                    break;
    
                case '*':
                case '/':
    
                    while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-'
                            && (*pTemp) -> op != '(' ) )
                    {        
                        transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                    }
    
                    alocaCharNaPilha( &( *pTemp ), aux, op );
                    
                    break;
    
                case ')':
                    while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                    {
                        transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                    }
    
                    if( (*pTemp) && (*pTemp) -> op == '(' )
                    {
                        aux = *pTemp;
                        *pTemp = (*pTemp) -> prox;
                        free( aux );
                    }
                    
                    break;

                case '0':
                    if (a=='/')    
                        div_zero=1;
    
                if (k==1){
                    alocaCharNaPilha( &( *pTemp ), aux, op );
                    
                    break;
                }
    
                default:
                    alocaCharNaPilha( &( *pPos ), aux, op );
                    
                    break;
            }
            a=op;
        }

        
        scanf( "%c", &op );
        
        if ( op != ' ' )
        {
            switch( op ){
                case '\n':
                    while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                    {
                        transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                    }
    
                    if( (*pTemp) && (*pTemp) -> op == '(' )
                    {
                        aux = *pTemp;
                        *pTemp = (*pTemp) -> prox;
                        free( aux );
                    }
                    
                    break;
    
            }

        }
        
    }
    
    return div_zero;
    free(aux);
}


typedef struct {
	float exp[100];
	int top;
} pilha;

void push(float e, pilha *s)
{
	s->top += 1;
	s->exp[s->top] = e;
}

float pop(pilha *s)
{
	float e;
	e = s->exp[s->top];
	s->top -= 1;
	return(e);
}

float stacktop(pilha *s)
{
	float e;
	e = s->exp[s->top];
	return(e);
}


void imprime( Pilha *topo)
{
    pilha *s;
    s = malloc (sizeof (pilha));
	s->top = -1;                                    
	char *aux;
    aux= malloc(1);
    char *c;
    c = malloc (100 * sizeof (char));
    int *k;
    k = (int *)malloc(sizeof(int));
    *k=-1;
    while (topo)
	{
        *k=*k+1;
         *aux = topo->op;
        
        topo=topo->prox;
        
        c[*k]=*aux;
    }
    char *c2;
    c2 = malloc ((*k+1) * sizeof (char));
    int *i;
    i = (int *)malloc(sizeof(int));
    int *k2;
    k2 = (int *)malloc(sizeof(int));
    *k2=*k+1;
    *i=-1;
    while (*i < *k)
    {
        *i=*i+1;
        *k2=*k2-1;
        c2[*k2]=c[*i];

    }

    
    *i=-1;
    while (*i < *k-1)
    {
        *i=*i+1;
        printf("%c ",c2[*i]);

    }

    printf("%c",c2[*k]);
	
   free(k);
   free(k2);
   free(s);
   free(c);
   free(c2);
   free(i);
   free(aux);
}



void calcula( Pilha *topo)
{
    pilha *s;
    s = malloc (sizeof (pilha));
	s->top = -1;                                    
	char *aux;
    aux= (char *)malloc(sizeof(char));
	float *nd,*st,*res;
    nd= (float *)malloc(sizeof(float));
    st= (float *)malloc(sizeof(float));
    res= (float *)malloc(sizeof(float));
    char *c;
    c = malloc (100 * sizeof (char));
    int *k;
    k = (int *)malloc(sizeof(int));
    *k=-1;
    while (topo)
	{
        *k=*k+1;
         *aux = topo->op;
        
        topo=topo->prox;
        
        c[*k]=*aux;
    }
    char *c2;
    c2 = malloc ((*k+1) * sizeof (char));
    int *i;
    i = (int *)malloc(sizeof(int));
    int *k2;
    k2 = (int *)malloc(sizeof(int));
    *k2=*k+1;
    *i=-1;
    while (*i < *k)
    {
        *i=*i+1;
        *k2=*k2-1;
        c2[*k2]=c[*i];

    }

	
	*i=-1;
    while (*i < *k)
    {
        *i=*i+1;
		*aux = c2[*i];
        
		if(*aux >= '0' && *aux <= '9') 
			push((float)*aux-'0',&*s);            
		else
		{
			*st = pop(&*s);
	        *nd = pop(&*s);
	        switch (*aux)
		    {
		    case '+':	*res = *nd+*st;
		        break;
		        
		    case '-':	*res = *nd-*st;
		        break;
		    case '/':	*res = *nd/(*st);
		        break;
		        
		    case '*':	*res = *nd*(*st);
		        break;
		        
	    	}
	        push(*res,&*s);
		}
	}
   printf ("\n%.2f",pop(&*s));	
   free(k);
   free(k2);
   free(s);
   free(c);
   free(c2);
   free(i);
   free(nd);
   free(st);
   free(res);
   free(aux);
}

void delete( Pilha *topo)
{
    char *aux;
    aux= (char *)malloc(sizeof(char));
    free(topo);
    while (topo)
	{
        *aux = topo->op;
        topo=topo->prox;
        free(topo);
    }
    
   free(aux);
}




int main()
{
    Pilha *pPos;
    pPos = NULL;
    Pilha *pTemp;
    pTemp = NULL;
    int div_zero;
    div_zero=leOperacao( &pPos, &pTemp ); 
    if (div_zero==0)
    {
        imprime( pPos );
        calcula(pPos);
    }
    if (div_zero==1) printf("ERRO: DIVISAO POR ZERO ENCONTRADA.");
    printf( "\n" );
    delete(pPos);

    return 0;
    free(pPos);
    free(pTemp);

}