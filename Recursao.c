#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i1;
    int i2;
    int n;
    scanf("%d", &n);
    struct Produto
    {
        float subprodutos[n+2][52];
        float imposto[n+2];
        float preco_final[n+2];
        int id;
    };
    struct Produto produto;
    
    int k1=0;
    int k2;
    int k3;
    int k4;
    int ok[n+2];
    int okk=0;
    for (i1 = 0; i1 < n; i1++)
    {
        k1=k1+1;
        scanf("%f", &produto.subpr
        odutos[k1][0]);
        scanf("%f", &produto.subprodutos[k1][1]);
        k3=produto.subprodutos[k1][1];
        if (k3==0)
        {
            k3=1;
        }
        k4=2+k3;
        k2=1;
        for (i2 = 0; i2 < k3; i2++)
        {
            k2=k2+1;
            scanf("%f", &produto.subprodutos[k1][k2]);

        }
        scanf("%f", &produto.subprodutos[k1][k4]);
        produto.imposto[k1]=1+produto.subprodutos[k1][k4]/100;

    } 
    
    scanf("%d", &produto.id);

    k1=0;
    for (i1 = 0; i1 < n; i1++)
    {
        k1=k1+1;
        ok[k1]=0;
    }
    k1=0;
    for (i1 = 0; i1 < n; i1++)
    {
        k1=k1+1;
        produto.preco_final[k1]=0;
    }
    int i3;
    int i4;
    int i5;
    int k5;
    int k6;
    int k7;
    int k8;


    k5=0;
    for (i5 = 0; i5 <n; i5++)
    {
        k5=k5+1;
        if (produto.subprodutos[k5][0]==produto.id)
        {
            k8=k5;
            break;
        }
    }
    
        
        k1=0;
        for (i1 = 0; i1 < n; i1++)
        {
            k1=k1+1;
            if (produto.subprodutos[k1][1]==0)
            {
                produto.preco_final[k1]=(produto.subprodutos[k1][2])*produto.imposto[k1];
            
            }
        }




    
    int i7;
    int k10;

    for (i7 = 0; i7< 100; i7++)
    {
        okk=0;
        int k9=0;
        for (i4 = 0; i4 < 50; i4++)
        {
            k9=k9+1;
            k1=0;
            for (i1 = 0; i1 < n; i1++)
            {
                k1=k1+1;
                if (produto.subprodutos[k1][1]==k9 )
                {
                    k10=0;
                    k4=1;
                    for (i3 = 0; i3 <k9; i3++)
                    {
                        k4=k4+1;
                        k6=produto.subprodutos[k1][k4];
                        k5=0;
                        for (i5 = 0; i5 <n; i5++)
                        {
                            k5=k5+1;
                            if (produto.subprodutos[k5][0]==k6)
                            {
                                k7=k5;
                                break;
                            }
                        }
                        
                        if (produto.preco_final[k7]>0)
                        {
                            k10=k10+1;
                        }
                        if (produto.preco_final[k7]==0)
                        {
                            okk=1;
                            
                        }
                    }

                    if (k10==produto.subprodutos[k1][1] && ok[k1]==0)
                    {

                        k4=1;
                        for (i3 = 0; i3 <k9; i3++)
                        {
                            k4=k4+1;
                            k6=produto.subprodutos[k1][k4];
                            k5=0;
                            for (i5 = 0; i5 <n; i5++)
                            {
                                k5=k5+1;
                                if (produto.subprodutos[k5][0]==k6)
                                {
                                    k7=k5;
                                    break;
                                }
                            }
                            produto.preco_final[k1]=produto.preco_final[k1]+produto.preco_final[k7];
                            ok[k1]=1;
                           
                           

                            
                        }
                        produto.preco_final[k1]=produto.preco_final[k1]*produto.imposto[k1];

                    }

                    
                    

                
                }
            

            } 
        
        }
        
        if (okk==0)
        {
            break;
        }
    }

    printf("%.2f\n",produto.preco_final[k8]);


    return 0;

}