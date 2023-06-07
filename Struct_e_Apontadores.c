#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i;
    int n;
    int i2;
    scanf("%d", &n);
    int RA[n];
    struct Data
    {
        int dia[n+1];
        int mes[n+1];
        int ano[n+1];
    };
    struct Data data;
    struct Nome
    {
        char nm[n+2][60];
        int nm0[n+2][60];
    };
    struct Nome nome;
    char c;
    int k2=-1;
    int k3=-1;
    int k1;
    for (i = 0; i < n; i++)
    {
        k2=k2+1;
        scanf("%d", &RA[k2]);
        scanf("%d", &data.dia[k2]);
        scanf("%d", &data.mes[k2]);
        scanf("%d", &data.ano[k2]);
        scanf("%c", &nome.nm[k2][0]);

        fgets (nome.nm[k2], 60, stdin);
    } 
    scanf("%c", &c); 
    int i1;
    k2=-1;
    for (i = 0; i < n; i++)
    {
        k2=k2+1;
        k1=-1;
        for (i1 = 0; i1 < 60; i1++)
        {
            k1=k1+1;
            if(nome.nm[k2][k1]=='a' || nome.nm[k2][k1]=='A' )
            {                
                nome.nm0[k2][k1]=1;
            }
            if(nome.nm[k2][k1]=='b' || nome.nm[k2][k1]=='B')
            {
                nome.nm0[k2][k1]=2;
            }
            if(nome.nm[k2][k1]=='c' || nome.nm[k2][k1]=='C')
            {
                nome.nm0[k2][k1]=3;
            }
            if(nome.nm[k2][k1]=='d' || nome.nm[k2][k1]=='D')
            {
                nome.nm0[k2][k1]=4;
            }
            if(nome.nm[k2][k1]=='e' || nome.nm[k2][k1]=='E')
            {
                nome.nm0[k2][k1]=5;
            }
            if(nome.nm[k2][k1]=='f' || nome.nm[k2][k1]=='F')
            {
                nome.nm0[k2][k1]=6;
            }
            if(nome.nm[k2][k1]=='g' || nome.nm[k2][k1]=='G')
            {
                nome.nm0[k2][k1]=7;
            }
            if(nome.nm[k2][k1]=='h' || nome.nm[k2][k1]=='H')
            {
                nome.nm0[k2][k1]=8;
            }
            if(nome.nm[k2][k1]=='i' || nome.nm[k2][k1]=='I' )
            {
                nome.nm0[k2][k1]=9;
            }
            if(nome.nm[k2][k1]=='j' || nome.nm[k2][k1]=='J')
            {
                nome.nm0[k2][k1]=10;
            }
            if(nome.nm[k2][k1]=='k' || nome.nm[k2][k1]=='K')
            {
                nome.nm0[k2][k1]=11;
            }
            if(nome.nm[k2][k1]=='l' || nome.nm[k2][k1]=='L')
            {
                nome.nm0[k2][k1]=12;
            }
            if(nome.nm[k2][k1]=='m' || nome.nm[k2][k1]=='M')
            {
                nome.nm0[k2][k1]=13;
            }
            if(nome.nm[k2][k1]=='n' || nome.nm[k2][k1]=='N')
            {
                nome.nm0[k2][k1]=14;
            }
            if(nome.nm[k2][k1]=='o' || nome.nm[k2][k1]=='O')
            {
                nome.nm0[k2][k1]=15;
            }
            if(nome.nm[k2][k1]=='p' || nome.nm[k2][k1]=='P')
            {
                nome.nm0[k2][k1]=16;
            }
            if(nome.nm[k2][k1]=='q' || nome.nm[k2][k1]=='Q')
            {
                nome.nm0[k2][k1]=17;
            }
            if(nome.nm[k2][k1]=='r' || nome.nm[k2][k1]=='R')
            {
                nome.nm0[k2][k1]=18;
            }
            if(nome.nm[k2][k1]=='s' || nome.nm[k2][k1]=='S')
            {
                nome.nm0[k2][k1]=19;
            }
            if(nome.nm[k2][k1]=='t' || nome.nm[k2][k1]=='T')
            {
                nome.nm0[k2][k1]=20;
            }
            if(nome.nm[k2][k1]=='u' || nome.nm[k2][k1]=='U')
            {
                nome.nm0[k2][k1]=21;
            }
            if(nome.nm[k2][k1]=='v' || nome.nm[k2][k1]=='V')
            {
                nome.nm0[k2][k1]=22;
            }
            if(nome.nm[k2][k1]=='w' || nome.nm[k2][k1]=='W')
            {
                nome.nm0[k2][k1]=23;
            }
            if(nome.nm[k2][k1]=='x' || nome.nm[k2][k1]=='X')
            {
                nome.nm0[k2][k1]=24;
            }
            if(nome.nm[k2][k1]=='y' || nome.nm[k2][k1]=='Y')
            {
                nome.nm0[k2][k1]=25;
            }
            if(nome.nm[k2][k1]=='z' || nome.nm[k2][k1]=='Z')
            {
                nome.nm0[k2][k1]=26;
            }
            if(nome.nm[k2][k1]==' ')
            {
                nome.nm0[k2][k1]=0;
            }
            if(nome.nm[k2][k1]!='A' && nome.nm[k2][k1]!='B' && nome.nm[k2][k1]!='C' && nome.nm[k2][k1]!='D' && nome.nm[k2][k1]!='E' && nome.nm[k2][k1]!='F' && nome.nm[k2][k1]!='G' && nome.nm[k2][k1]!='H' && nome.nm[k2][k1]!='I' && nome.nm[k2][k1]!='J' && nome.nm[k2][k1]!='K' && nome.nm[k2][k1]!='L' && nome.nm[k2][k1]!='M' && nome.nm[k2][k1]!='N' && nome.nm[k2][k1]!='O' && nome.nm[k2][k1]!='P' && nome.nm[k2][k1]!='Q' && nome.nm[k2][k1]!='R' && nome.nm[k2][k1]!='S' && nome.nm[k2][k1]!='T' && nome.nm[k2][k1]!='U' && nome.nm[k2][k1]!='V' && nome.nm[k2][k1]!='W' && nome.nm[k2][k1]!='X' && nome.nm[k2][k1]!='Y' && nome.nm[k2][k1]!='Z' && nome.nm[k2][k1]!=' ' && nome.nm[k2][k1]!='a' && nome.nm[k2][k1]!='b' && nome.nm[k2][k1]!='c' && nome.nm[k2][k1]!='d' && nome.nm[k2][k1]!='e' && nome.nm[k2][k1]!='f' && nome.nm[k2][k1]!='g' && nome.nm[k2][k1]!='h' && nome.nm[k2][k1]!='i' && nome.nm[k2][k1]!='j' && nome.nm[k2][k1]!='k' && nome.nm[k2][k1]!='l' && nome.nm[k2][k1]!='m' && nome.nm[k2][k1]!='n' && nome.nm[k2][k1]!='o' && nome.nm[k2][k1]!='p' && nome.nm[k2][k1]!='q' && nome.nm[k2][k1]!='r' && nome.nm[k2][k1]!='s' && nome.nm[k2][k1]!='t' && nome.nm[k2][k1]!='u' && nome.nm[k2][k1]!='v' && nome.nm[k2][k1]!='w' && nome.nm[k2][k1]!='x' && nome.nm[k2][k1]!='y' && nome.nm[k2][k1]!='z')
            {
                nome.nm0[k2][k1]=100;
            }
        }
    }   


    int i4;
    int k5;
    int k6;
    if (c=='R')
    { 
        for (i = 0; i < 100000; i++)
        {            
            k5=-1;
            k6=0;
            for (i4 = 0; i4 < (n-1); i4++)
            {
                k5=k5+1;
                if(RA[k5]<=RA[k5+1])
                {
                    k6=k6+1;
                }
            }
            if (k6==(n-1))
            {
                break;
            }
            k1=-1;
            for (i1 = 0; i1 < (n-1); i1++)
            {
                k1=k1+1;
                k2=k1+1;
                if(RA[k1]>RA[k2])
                {
                    i=RA[k2];
                    RA[k2]=RA[k1];
                    RA[k1]=i;

                    i=data.dia[k2];
                    data.dia[k2]=data.dia[k1];
                    data.dia[k1]=i;

                    i=data.mes[k2];
                    data.mes[k2]=data.mes[k1];
                    data.mes[k1]=i;

                    i=data.ano[k2];
                    data.ano[k2]=data.ano[k1];
                    data.ano[k1]=i;

                    
                    strcpy(nome.nm[n], nome.nm[k2]);
                    strcpy(nome.nm[k2], nome.nm[k1]);
                    strcpy(nome.nm[k1], nome.nm[n]);
                    
                    
                }
            }
        }
        RA[n]='\0';
        data.dia[n]='\0';
        data.mes[n]='\0';
        data.ano[n]='\0';
       
    }    
    if(c=='D')
    {
        
        for (i = 0; i < 100000; i++)
        {            
            k5=-1;
            k6=0;
            for (i4 = 0; i4 < (n-1); i4++)
            {
                k5=k5+1;
                if(data.ano[k5]<=data.ano[k5+1])
                {
                    k6=k6+1;
                }
            }
            if (k6==(n-1))
            {
                break;
            }
            k1=-1;
            for (i1 = 0; i1 < (n-1); i1++)
            {
                k1=k1+1;
                k2=k1+1;
                if(data.ano[k1]>data.ano[k2])
                {
                    i=RA[k2];
                    RA[k2]=RA[k1];
                    RA[k1]=i;

                    i=data.dia[k2];
                    data.dia[k2]=data.dia[k1];
                    data.dia[k1]=i;

                    i=data.mes[k2];
                    data.mes[k2]=data.mes[k1];
                    data.mes[k1]=i;

                    i=data.ano[k2];
                    data.ano[k2]=data.ano[k1];
                    data.ano[k1]=i;

                    strcpy(nome.nm[n], nome.nm[k2]);
                    strcpy(nome.nm[k2], nome.nm[k1]);
                    strcpy(nome.nm[k1], nome.nm[n]);
                }
            }
        }
        for (i = 0; i < n*2; i++)
        {            
            
            k1=-1;
            for (i1 = 0; i1 < (n-1); i1++)
            {
                k1=k1+1;
                k2=k1+1;
                if(data.ano[k1]==data.ano[k2] && data.mes[k1]>data.mes[k2])
                {
                    i=RA[k2];
                    RA[k2]=RA[k1];
                    RA[k1]=i;

                    i=data.dia[k2];
                    data.dia[k2]=data.dia[k1];
                    data.dia[k1]=i;

                    i=data.mes[k2];
                    data.mes[k2]=data.mes[k1];
                    data.mes[k1]=i;

                    i=data.ano[k2];
                    data.ano[k2]=data.ano[k1];
                    data.ano[k1]=i;

                    strcpy(nome.nm[n], nome.nm[k2]);
                    strcpy(nome.nm[k2], nome.nm[k1]);
                    strcpy(nome.nm[k1], nome.nm[n]);
                }
            }
        }
        for (i = 0; i < n*2; i++)
        {            
            k1=-1;
            for (i1 = 0; i1 < (n-1); i1++)
            {
                k1=k1+1;
                k2=k1+1;
                if(data.ano[k1]==data.ano[k2] && data.mes[k1]==data.mes[k2] && data.dia[k1]>data.dia[k2])
                {
                    i=RA[k2];
                    RA[k2]=RA[k1];
                    RA[k1]=i;
                    i=data.dia[k2];
                    data.dia[k2]=data.dia[k1];
                    data.dia[k1]=i;
                    i=data.mes[k2];
                    data.mes[k2]=data.mes[k1];
                    data.mes[k1]=i;
                    i=data.ano[k2];
                    data.ano[k2]=data.ano[k1];
                    data.ano[k1]=i;
                    strcpy(nome.nm[n], nome.nm[k2]);
                    strcpy(nome.nm[k2], nome.nm[k1]);
                    strcpy(nome.nm[k1], nome.nm[n]);
                }
            }
        }
        RA[n]='\0';
        data.dia[n]='\0';
        data.mes[n]='\0';
        data.ano[n]='\0';
    }
    int i7;
    int i8;
    int i10;
    int i11;
    int k9;
    int k7;
    int k8;
    if (c=='N')
    {
        for (i7 = 0; i7 < 100000; i7++)
        {            
            k5=-1;
            k6=0;
            for (i4 = 0; i4 < (n-1); i4++)
            {
                k5=k5+1;
                if(nome.nm0[k5][0]<=nome.nm0[k5+1][0])
                {
                    k6=k6+1;
                }
            }   
            if (k6==(n-1))
            {
                break;
            }
            k1=-1;
            for (i1 = 0; i1 < (n-1); i1++)
            {
                k1=k1+1;
                k2=k1+1;
                if(nome.nm0[k1][0]>nome.nm0[k2][0])
                {
                    i=RA[k2];
                    RA[k2]=RA[k1];
                    RA[k1]=i;
                    i=data.dia[k2];
                    data.dia[k2]=data.dia[k1];
                    data.dia[k1]=i;
                    i=data.mes[k2];
                    data.mes[k2]=data.mes[k1];
                    data.mes[k1]=i;
                    i=data.ano[k2];
                    data.ano[k2]=data.ano[k1];
                    data.ano[k1]=i;
                    strcpy(nome.nm[n], nome.nm[k2]);
                    strcpy(nome.nm[k2], nome.nm[k1]);
                    strcpy(nome.nm[k1], nome.nm[n]);
                    k3=-1;
                    for (i2 = 0; i2 < 60; i2++)
                    {
                        k3=k3+1;
                        i=nome.nm0[k2][k3];
                        nome.nm0[k2][k3]=nome.nm0[k1][k3];
                        nome.nm0[k1][k3]=i;
                    }
                }
            }
        }
        for (i8 = 0; i8 < n*5; i8++)
        {
            k9=0;
            for (i10 = 0; i10 < 59; i10++)     
            {
                k9=k9+1;       

                k1=-1;
                for (i1 = 0; i1 < (n-1); i1++)
                {
                    k1=k1+1;
                    k2=k1+1;
                    k7=-1;
                    k8=0;
                    for (i11 = 0; i11 < k9; i11++)     
                    {
                        k7=k7+1;
                        if(nome.nm0[k1][k7]==nome.nm0[k2][k7])
                        {
                            k8=k8+1;
                        }
                    }
                    if(k8==k9 && nome.nm0[k1][k7+1]>nome.nm0[k2][k7+1]) 
                    {
                        i=RA[k2];
                        RA[k2]=RA[k1];
                        RA[k1]=i;
                        i=data.dia[k2];
                        data.dia[k2]=data.dia[k1];
                        data.dia[k1]=i;
                        i=data.mes[k2];
                        data.mes[k2]=data.mes[k1];
                        data.mes[k1]=i;
                        i=data.ano[k2];
                        data.ano[k2]=data.ano[k1];
                        data.ano[k1]=i;
                        strcpy(nome.nm[n], nome.nm[k2]);
                        strcpy(nome.nm[k2], nome.nm[k1]);
                        strcpy(nome.nm[k1], nome.nm[n]);
                        k3=-1;
                        for (i2 = 0; i2 < 60; i2++)
                        {
                            k3=k3+1;
                            i=nome.nm0[k2][k3];
                            nome.nm0[k2][k3]=nome.nm0[k1][k3];
                            nome.nm0[k1][k3]=i;
                        }
                    }
                }
            }
        }

        RA[n]='\0';
        data.dia[n]='\0';
        data.mes[n]='\0';
        data.ano[n]='\0';
    }
    k1=-1;
    for (i = 0; i < n; i++)
    {      
        k1=k1+1;
        printf("%06d %02d %02d %04d %s",RA[k1],data.dia[k1],data.mes[k1],data.ano[k1],nome.nm[k1]);   
    }
    return 0;
}




