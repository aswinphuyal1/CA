//Booth’s Multiplication Algorithm
#include <stdio.h>
    void
    add(int a[], int x[], int q);
void complement(int a[], int n)
{
    int i;
    int x[8] = {0};
    x[0] = 1;
    for (i = 0; i < n; i++)
    {
        a[i] = (a[i] + 1) % 2;
    }
    add(a, x, n);
}
void add(int ac[], int x[], int q)
{
    int i, c = 0;
    for (i = 0; i < q; i++)
    {
        ac[i] = ac[i] + x[i] + c;
        if (ac[i] > 1)
        {
            ac[i] = ac[i] % 2;
            c = 1;
        }
        else
            c = 0;
    }
}
void ashr(int ac[], int qr[], int *qn, int q)
{
    int temp, i;
    temp = ac[0];
    *qn = qr[0];
    printf("\t\tashr\t\t");
    for (i = 0; i < q - 1; i++)
    {
        ac[i] = ac[i + 1];
        qr[i] = qr[i + 1];
    }
    qr[q - 1] = temp;
}
void display(int ac[], int qr[], int qrn)
{
    int i;
    for (i = qrn - 1; i >= 0; i--)
        printf("%d", ac[i]);
    printf(" ");
    for (i = qrn - 1; i >= 0; i--)
        printf("%d", qr[i]);
}

int main()
{
    int mt[10], br[10], qr[10], sc, ac[10] = {0};
    int brn, qrn, i, qn, temp;
    printf("\n");
    printf("\tComplie by Aswin phuyal\n");
    printf("\tBooth's Algorithm\n");
    printf("\n Number of multiplicand bit= ");
    scanf("%d", &brn);
    printf("\nmultiplicand= ");

    for (i = brn - 1; i >= 0; i--)
        scanf("%d", &br[i]); // multiplicand
    for (i = brn - 1; i >= 0; i--)
        mt[i] = br[i];
    complement(mt, brn);
    printf("\nNo. of multiplier bit= ");
    scanf("%d", &qrn);
    sc = qrn;
    printf("Multiplier= ");

    for (i = qrn - 1; i >= 0; i--)
        scanf("%d", &qr[i]);
    qn = 0;
    temp = 0;
    printf("qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tsc\n");
    printf("\t\t\tinitial\t\t");

    display(ac, qr, qrn);
    printf("\t\t%d\n", sc);
    while (sc != 0)
    {
        printf("%d\t%d", qr[0], qn);
        if ((qn + qr[0]) == 1)
        {
            if (temp == 0)
            {
                add(ac, mt, qrn);
                printf("\t\tsubtracting BR\t");
                for (i = qrn - 1; i >= 0; i--)
                    printf("%d", ac[i]);
                temp = 1;
            }
            else if (temp == 1)
            {
                add(ac, br, qrn);
                printf("\t\tadding BR\t");
                for (i = qrn - 1; i >= 0; i--)
                    printf("%d", ac[i]);
                temp = 0;
            }
            printf("\n\t");
            ashr(ac, qr, &qn, qrn);
        }
        else if (qn - qr[0] == 0)
            ashr(ac, qr, &qn, qrn);
        display(ac, qr, qrn);
        printf("\t");
        sc--;
        printf("\t%d\n", sc);
    }
    printf("Result= ");
    display(ac, qr, qrn);
}
