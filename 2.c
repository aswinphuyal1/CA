//Restoring Division Algorithm

#include <stdio.h>
void print_binary(int num, int bits)
{
    int i;
    for (i = bits - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
}
void print_step(int step, const char *op, int A, int Q, int bits)
{
    printf("| %-12s |  ", op);
    print_binary(A, bits);
    printf("  |  ");
    print_binary(Q, bits);
    if (op == "Initialize")
        printf("  | %2d  |\n", step);
    else if (op == "Restore A" || op == "Set Q0=1")
        printf("  | %2d  |\n", step - 1);
    else
        printf("  |     |\n");
}

int main()
{
    int dividend, divisor;
    int bits = 4;
    int A, Q, M;
    int sc;
    printf("\n");
    printf("\t Complied by Aswin phuyal \n");
    printf(" Restoring Division Algorithm (4-bit) \n");
    printf("Enter Dividend Q (0 - 15): ");
    scanf("%d", &dividend);
    printf("Enter Divisor M (0 - 15): ");
    scanf("%d", &divisor);
    A = 0;
    Q = dividend;
    M = divisor;
    sc = bits;
    printf("\n+--------------+--------+--------+-----+\n");
    printf("| Operation    |   A    |   Q    |  SC |\n");
    printf("+--------------+--------+--------+-----+\n");
    print_step(sc, "Initialize", A, Q, bits);

    for (sc = bits; sc > 0; sc--)
    {
        // Shift AQ left
        A = (A << 1) | ((Q >> (bits - 1)) & 1);
        Q <<= 1;
        print_step(sc, "Shift AQ", A, Q, bits);

        // Subtract M from A
        A -= M;
        print_step(sc, "A = A - M", A, Q, bits);

        if (A < 0)
        {
            A += M; // Restore
            print_step(sc, "Restore A", A, Q, bits);
        }
        else
        {
            Q |= 1; // Set LSB
            print_step(sc, "Set Q0=1", A, Q, bits);
        }
    }
    printf("+--------------+--------+--------+-----+\n");
    printf("\nResult: Quotient = %d, Remainder = %d\n", Q & 0xF, A & 0xF); // Mask to 4 bits
}
