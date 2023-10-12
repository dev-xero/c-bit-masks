# `C BIT MASKS`

```c
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
```
