#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int i;
    float l2[n];
    for (i = 0; i < n; i++)
    {
        scanf("%f", &l2[i]);
    }

    char l1[n * 2];
    scanf("%c", &l1[0]);
    if (l1[0]!=' '){
        for (i = 1; i < n * 2; i++)
        {
            scanf("%c", &l1[i]);
        }
    }
    if (l1[0]==' '){
        for (i = 0; i < n * 2; i++)
        {
            scanf("%c", &l1[i]);
        }
    }
    

    float l3[n];
    for (i = 0; i < n; i++)
    {
        scanf("%f", &l3[i]);
    }

    float a;
    int k1 = -1;
    int k2 = -1;
    for (i = 0; i < n; i++)
    {
        k1 = k1 + 1;
        k2 = k2 + 2;

        if (l1[k2] == '*')
        {
            a = l2[k1] * l3[k1];
            printf("%.4f * %.4f = %.4f\n", l2[k1], l3[k1], a);
        }

        if (l1[k2] == '/')
        {
            a = l2[k1] / l3[k1];
            printf("%.4f / %.4f = %.4f\n", l2[k1], l3[k1], a);
        }

        if (l1[k2] == '+')
        {
            a = l2[k1] + l3[k1];
            printf("%.4f + %.4f = %.4f\n", l2[k1], l3[k1], a);
        }

        if (l1[k2] == '-')
        {
            a = l2[k1] - l3[k1];
            printf("%.4f - %.4f = %.4f\n", l2[k1], l3[k1], a);
        }
    }

    return 0;
}