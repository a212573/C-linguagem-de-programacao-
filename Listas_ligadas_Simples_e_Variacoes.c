#include <stdio.h>
#include <stdlib.h>


typedef struct Elemento
{
	int *valor;
	int *linha;
	int *coluna;
	struct Elemento *prox_na_linha;
	struct Elemento *prox_na_coluna;
}Elemento;

typedef struct Matriz
{
	struct Elemento *no_cabeca;
	int *lin, *col;
	int *dif_zero;
}Matriz;





Elemento *existe(Matriz *a, int *linha, int *coluna)
{
	linha = (int *)malloc(sizeof(int));
	coluna = (int *)malloc(sizeof(int));
	a = malloc(sizeof(Matriz));
	int *k;
	k = (int *)malloc(sizeof(int));
	Elemento *p0 = NULL, *p1 = NULL;
	p0 = malloc(sizeof(Elemento));
	p1 = malloc(sizeof(Elemento));

	
	p0 = a->no_cabeca->prox_na_coluna;
	for(k=0; k<linha; k++)
		p0 = p0->prox_na_coluna;
	p1 = p0->prox_na_linha;
	for(k=0; k<coluna; k++)
	{
		if(p1->coluna == coluna && p1->linha == linha) 
			return p1;
		p1 = p1->prox_na_linha;
	}

	if(p1->coluna == coluna && p1->linha == linha) 
		return p1;
	return NULL;
	free(k);
	free(p0);
	free(p1);
	free(linha);
	free(coluna);
	free(a);

} 

void deletar(Matriz *a, int *linha, int *coluna)
{
	int *k;
	k = (int *)malloc(sizeof(int));
	linha = (int *)malloc(sizeof(int));
	coluna = (int *)malloc(sizeof(int));
	a = malloc(sizeof(Matriz));
	
	Elemento *e = existe(a,linha,coluna);
	e = malloc(sizeof(Elemento));


	Elemento *p0, *p1; 
	p0 = malloc(sizeof(Elemento));
	p1 = malloc(sizeof(Elemento));

	p0=NULL;
	p1=NULL;



	if(!e) return;
	
	p0 = a->no_cabeca->prox_na_coluna;
	for(k=0; k<linha; k++)
		p0 = p0->prox_na_coluna;
	p1 = p0->prox_na_linha;
	while((p1->prox_na_linha != e))
		p1 = p1->prox_na_linha;
	p1->prox_na_linha = e->prox_na_linha;
	
	p0 = a->no_cabeca->prox_na_linha;
	for(k=0; k<coluna; k++)
		p0 = p0->prox_na_linha;
	p1 = p0->prox_na_coluna;
	while(p1->prox_na_coluna != e)
		p1 = p1->prox_na_coluna;
	p1->prox_na_coluna = e->prox_na_coluna;

	a->dif_zero--;
	free(e);
	free(k);
	free(p0);
	free(p1);
	free(linha);
	free(coluna);
	free(a);


	return;
}



void imprimir(Matriz *a)
{
	a = malloc(sizeof(Matriz));
	int *linha, *coluna;
	linha = (int *)malloc(sizeof(int));
	coluna= (int *)malloc(sizeof(int));
	Elemento *p0 = NULL, *p1 = NULL;	
	p0 = malloc(sizeof(Elemento));
	p1 = malloc(sizeof(Elemento));
	p0 = a->no_cabeca->prox_na_coluna;
	for(linha=0; linha<a->lin; linha++)
	{
		p1 = p0->prox_na_linha;
		for(coluna=0; coluna<a->col; coluna++)
		{
			    Elemento *e = existe(a,linha,coluna);
				int *v;
				v = e->valor;

				if(e) 
					printf("%d\t", *v);
				else 
					printf("0\t");
			if(p1->coluna == coluna)
				p1 = p1->prox_na_linha;
			printf("\n");
		}
		p0 = p0->prox_na_coluna;
	}
	return;
	free(linha);
	free(coluna);
	free(p0);
	free(p1);
	free(a);
}

void inserir(Matriz *a, int *linha, int *coluna, int *valor)
{
	linha = (int *)malloc(sizeof(int));
	coluna = (int *)malloc(sizeof(int));
	a = malloc(sizeof(Matriz));
	int *k;
	k = (int *)malloc(sizeof(int));
	Elemento *no_cabeca_col = NULL, *no_cabeca_lin = NULL, *p_col = NULL, *p_lin = NULL;
	Elemento *e = existe(a,linha,coluna);
	no_cabeca_col = malloc(sizeof(Elemento));
	no_cabeca_lin = malloc(sizeof(Elemento));
	p_col = malloc(sizeof(Elemento));
	p_lin = malloc(sizeof(Elemento));
	e = malloc(sizeof(Elemento));


	if(e) deletar(a, linha, coluna); 
	
	Elemento *novo;
	novo = malloc(sizeof(Elemento));
	novo= (Elemento *)malloc(sizeof(Elemento));
	novo->linha = linha;
	novo->coluna = coluna;
	novo->valor = valor;

	no_cabeca_lin = a->no_cabeca->prox_na_coluna;
	for(k=0; k<linha; k++)
		no_cabeca_lin = no_cabeca_lin->prox_na_coluna;
	
	no_cabeca_col = a->no_cabeca->prox_na_linha;
	for(k=0; k<coluna; k++)
		no_cabeca_col = no_cabeca_col->prox_na_linha;
	

	p_lin = no_cabeca_lin;
	while(1)
	{
		if((p_lin->prox_na_linha != no_cabeca_lin) && (p_lin->prox_na_linha->coluna < coluna))
			p_lin = p_lin->prox_na_linha;
		else
			break;
	}
	
	p_col = no_cabeca_col;
	while(1)
	{
		if((p_col->prox_na_coluna != no_cabeca_col) && (p_col->prox_na_coluna->linha < linha))
			p_col = p_col->prox_na_coluna;
		else
			break;
	}


	novo->prox_na_linha = p_lin->prox_na_linha;
	novo->prox_na_coluna = p_col->prox_na_coluna;
	p_lin->prox_na_linha = novo;
	p_col->prox_na_coluna = novo;
	
	
	a->dif_zero++;

	if(!valor) deletar(a, linha, coluna);
	
	return;

	free(linha);
	free(coluna);
	free(a);
	free(k);
	free(no_cabeca_col);
	free(coluna);
	free(no_cabeca_lin);
	free(p_col);
	free(p_lin);
	free(e);
	free(novo);
	
}









Matriz soma(Matriz *a, Matriz *b)
{
	a = malloc(sizeof(Matriz));
	b = malloc(sizeof(Matriz));
	int *i1;
	int *i2;
	int *i3;
	i1 = (int *)malloc(sizeof(int));
	i2 = (int *)malloc(sizeof(int));
	i3 = (int *)malloc(sizeof(int));
	Matriz *S;
	S = malloc(sizeof(Matriz));
	Elemento *pa0 = NULL, *pa1 = NULL, *pb0 = NULL, *pb1 = NULL;
	int *linha,*coluna;
	pa0 = malloc(sizeof(Elemento));
	pa1 = malloc(sizeof(Elemento));
	pb0 = malloc(sizeof(Elemento));
	pb1 = malloc(sizeof(Elemento));
	linha = (int *)malloc(sizeof(int));
	coluna = (int *)malloc(sizeof(int));

	

	pa0 = a->no_cabeca->prox_na_coluna;
	pb0 = b->no_cabeca->prox_na_coluna;
	for(linha=0; linha<a->lin; linha++)
	{
		pa1 = pa0->prox_na_linha;
		pb1 = pb0->prox_na_linha;
		printf("oi0\n");
		for(coluna=0; coluna<a->col; coluna++)
		{
			if(pa1->coluna == coluna && pb1->coluna ==coluna)
			{
				i1=pa1->valor;
				i2=pb1->valor;
				*i3=*i1 + *i2;
				
				inserir(S, linha, coluna, i3);
				if(pa1 != pa0) pa1 = pa1->prox_na_linha;
				if(pb1 != pb0) pb1 = pb1->prox_na_linha;
				printf("oi1\n");
			}

			else if(pa1->coluna == coluna)
			{
				inserir(S, linha, coluna, pa1->valor);
				printf("oi2\n");
				if(pa1 != pa0) pa1 = pa1->prox_na_linha;
			}
			else if(pb1->coluna == coluna)
			{
				inserir(S, linha, coluna, pb1->valor);
				printf("oi3\n");
				if(pb1 != pb0) pb1 = pb1->prox_na_linha;
			}
			else{
				inserir(S, linha, coluna, 0);
				printf("oi4\n");
			}
			
		}
		pa0 = pa0->prox_na_coluna;
		pb0 = pb0->prox_na_coluna;
	}
	return *S;
	printf("oi\n");


	free(a);
	free(b);
	free(i1);
	free(i2);
	free(i3);
	free(S);
	free(pa0);
	free(pa1);
	free(pb0);
	free(pb1);
	free(linha);
	free(coluna);

}














void criar_matriz(Matriz *a, int *lin, int *col)
{
	int *linha;
	int *i1;
	int *i2;
	i1 = (int *)malloc(sizeof(int));
	i2 = (int *)malloc(sizeof(int));
	linha = (int *)malloc(sizeof(int));
	lin = (int *)malloc(sizeof(int));
	col = (int *)malloc(sizeof(int));
	a = malloc(sizeof(Matriz));

	printf("oi!");

	


	*i1=-1;
	*i2=0;
	
	Elemento *p = NULL;
	p = malloc(sizeof(Elemento));
	printf("oi!");

	a->lin = lin;
	a->col = col;
	a->dif_zero = 0;
	printf("oi!");

	a->no_cabeca = (Elemento *)malloc(sizeof(Elemento));
	a->no_cabeca->linha = i1;
	a->no_cabeca->coluna = i1;
	a->no_cabeca->valor = i2;
	printf("oi!");
	
	p = a->no_cabeca;
	for(linha=0; linha<lin; linha++)
	{
		p->prox_na_coluna = (Elemento *)malloc(sizeof(Elemento));
		p->prox_na_coluna->prox_na_linha = p->prox_na_coluna;
		
		p->prox_na_coluna->valor = 0;
		p->prox_na_coluna->linha = p->prox_na_coluna->coluna = i1;
		
		p = p->prox_na_coluna;
	}
	p->prox_na_coluna = a->no_cabeca;
	printf("oi!");
	
	p = a->no_cabeca;
	for(linha=0;linha<col; linha++)
	{
		p->prox_na_linha = (Elemento *)malloc(sizeof(Elemento));
		p->prox_na_linha->prox_na_coluna = p->prox_na_linha;
		
		p->prox_na_linha->valor = 0;
		p->prox_na_linha->linha = p->prox_na_linha->coluna = i1;
		
		p = p->prox_na_linha;
	}
	p->prox_na_linha = a->no_cabeca;
	printf("oi!");
	
	return;
	printf("oi!");

	free(i1);
	free(i2);
	free(linha);
	free(lin);
	free(col);
	free(a);
	free(p);
	printf("oi!");
}








int main()
{
	Matriz *A[2];
	A[2] = malloc(sizeof(Matriz));
	int *i1;
    int *n=0;
	int *a;
	int *b;
	int *c;
    int *z=0;
    n = (int *)malloc(sizeof(int));
	z = (int *)malloc(sizeof(int));

    
    
    scanf("%d", &*n);
    
    printf("oi!");

    i1 = (int *)malloc(sizeof(int));
    
    a = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));
    c = (int *)malloc(sizeof(int));
    criar_matriz(A[0], n, n);
	criar_matriz(A[1], n, n);
	inserir(A[0],n, n, 0);
	inserir(A[1],n, n, 0);



    for (i1 = 0; i1 < n; i1++)
    {
		printf("oi!!");
        
        scanf("%d", &*a);
        scanf("%d", &*b);
        scanf("%d", &*c);

          
        if (*a==-1 && *b==-1 && *c==-1)
        {
            break;
        }
        printf("oi!");
        if( a<=n && a> z && b<= n && b>z)
        {
            *a=*a-1;
            *b=*b-1;
            *c=*c-1;
		    inserir(A[0],a, b, c);

        }
        

    } 
    for (i1 = 0; i1 < n; i1++)
    {
		printf("oi!");
        
        scanf("%d", &*a);
        scanf("%d", &*b);
        scanf("%d", &*c);


        if (*a==-1 && *b==-1 && *c==-1)
        {
			printf("oiiiiiii\n");
            break;
        }
        if( a<=n && a> z && b<= n && b>z)
        {
            *a=*a-1;
            *b=*b-1;
            *c=*c-1;
		    inserir(A[1],a, b, c);

        }

    }
	Matriz *S;
	S = malloc(sizeof(Matriz));
	
	*S=soma(A[0],A[1]);
	printf("oiiiiiii\n");
	imprimir(S);
	printf("oiiiiiii\n");



    free(z);
    free(n);

    free(a);
    free(b);
    free(c);
    free(i1);

	
	
	return 0;
}
