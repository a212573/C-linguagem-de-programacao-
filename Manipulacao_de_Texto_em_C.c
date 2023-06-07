#include <stdio.h>
#include <string.h>

int main()
{

    int i;
    int k3=0;
    int t1=0;
    int t2=0;
    char a[1500];
    char b[30];
    int k=-1;
    for (i = 0; i < 1500; i++)
    {
        k=k+1;
        scanf("%c", &a[k]);
        t1=t1+1;
        if (a[k]=='\n')
        {
        
            k3=1;
            break;
        }
    
    }

    if (k3==1){
        
        fgets (b, 30, stdin);
        
    }
    
    t2=strlen(b);

    if(b[0]=='c' && b[1]=='o' && b[2]=='n' && b[3]=='s' && b[4]=='i' && b[5]=='d')
    {
        t2=30;
    }
    if(t2>30)
    {
        t2=30;
    }


    int k1;
    int k2;
    int k4;
    int k5;
    int k6;
    int x1=0;
    int x2;
    int x3;
    int i1;
    k1=-1;
    for (i = 0; i < (t1-t2+1); i++)
    {
        k1=k1+1;
        k2=k1-1;
        k3=-1;
        k4=0;
        k5=0;
        for (i = 0; i < t2; i++)
        {
            k2=k2+1;
            k3=k3+1;
            k5=k5+1;
            x2=k1+1;
            x3=x2+t2-1;
            if(a[k2]==b[k3])
            {   
                k4=k4+1;
                
            }

            if(k4>=(t2-1) && k5==t2)
            {
                x1=x1+1;    
                if(x1==1)
                {
                    
                    printf("%03d %03d %03d ", x1,x2,x3);
                    k6=k1-1;
                    for (i1 = 0; i1 < t2; i1++)
                    {
                        k6=k6+1;
                        printf("%c",a[k6]);

                    }
                }
                if(x1>1)
                {
                    
                    printf("\n%03d %03d %03d ", x1,x2,x3);
                    k6=k1-1;
                    for (i1 = 0; i1 < t2; i1++)
                    {
                        k6=k6+1;
                        printf("%c",a[k6]);

                    }
                }
            }
        }
        if(k1==(t1-t2+1) && x1==0)
        {   
            printf("Nenhuma ocorrencia encontrada");
            break;
                
        }

        if(x3==(t1+1))
        {   
            break;
        }

        if(x3==(500) && x1==0)
        {   
            printf("Nenhuma ocorrencia encontrada");
            break;
        }

        if(x3==(500))
        {   
            break;
        }
    
    }


    return 0;
}