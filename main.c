#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t length)
{
    /**
     * Displays the bytes of a value.
     * The bytes are printed in reverse-order to simulate big-endian byte ordering on little-endian
     * processors
    */

    printf("0x");
    for (int i = length-1; i > -1; i--)
    {
        printf(" %.2x", start[i]);
    }
}

void least_significant_bytes(int *x)
{
    int res = *x & 0xFF;    
    show_bytes((byte_pointer) &res, sizeof(res));
}

void byte_complement(int *x)
{
    int res = ~*x;
    show_bytes((byte_pointer) &res, sizeof(res));
}

void byte_complement_until_least_sig(int *x)
{
    int res = *x ^ ~0xFF;
    show_bytes((byte_pointer) &res, sizeof(res));
}

void least_sig_bytes_set_to_ones(int *x)
{
    int res = *x | 0xFF;
    show_bytes((byte_pointer) &res, sizeof(res));
}

int main()
{
    int a = -2023406815;
    show_bytes((byte_pointer) &a, sizeof(a));

    printf("\n\nLEAST SIGNIFICANT BYTES:\n");
    least_significant_bytes(&a);

    printf("\n\nBYTE COMPLEMENT:\n");
    byte_complement(&a);

    printf("\n\nBYTE COMPLEMENT, UNTIL LEAST SIG. BYTES:\n");
    byte_complement_until_least_sig(&a);

    printf("\n\nLEAST SIG. BYTES SET TO ONES:\n");
    least_sig_bytes_set_to_ones(&a);

    return 0;
}