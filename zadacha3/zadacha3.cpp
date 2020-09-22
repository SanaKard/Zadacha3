#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned char Invert(unsigned char x)
{
    int base = 256;
    unsigned char res = 0;

    while (x != 0)
    {
        res += (x & 1) * (base >>= 1);
        x >>= 1;
    }

    return res;
}

int main()
{
    FILE* f1;
    FILE* f2;
    FILE* f3;
    int a = 0, b = 0, c = 0;
    int flag1 = 0, flag2 = 0;

    f1 = fopen("binaryData1.info", "r");
    f2 = fopen("binaryData2.info", "r");
    f3 = fopen("unionBinaryData.info", "w");

    if (f1 == NULL || f2 == NULL) {
        printf("ошибка1\n");

        return -1;
    }

    while (1)
    {
        if ((a = getc(f1)) == EOF)
        {
            flag1 = 1;
            a = 0;
        }

        if ((b = getc(f2)) == EOF)
        {
            flag2 = 1;
            b = 0;
        }

        if (flag1 && flag2)
            break;
        
        c = a | b;

        fputc(Invert(c), f3);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}