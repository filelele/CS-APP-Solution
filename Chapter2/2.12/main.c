/*Write C expressions, in terms of variable x, for the following values. Your code
should work for any word size w ≥ 8. For reference, we show the result of evaluating
the expressions for x = 0x87654321, with w = 32.
A. The least significant byte of x, with all other bits set to 0. [0x00000021]
B. All but the least significant byte of x complemented, with the least significant
byte left unchanged. [0x789ABC21]*
C. The least significant byte set to all ones, and all other bytes of x left unchanged.
[0x876543FF]*/

#include<stdio.h>

void printByte(char* a, int asize){
    for(int i = 0;i < asize; ++i, ++a){
        printf("%X ", *a);
    }
    printf("\n");
}

#define BITMASK 0x00000000000000FF

void maskA(void* a, int asize){
    printf("Initial bits: ");
    char* bp = (char*)a;
    printByte(bp, asize);

    if(asize == 4){
        unsigned int* op1 = (unsigned int*)bp;
        *op1 = *op1 & BITMASK;
    }
    else if(asize == 8){
        unsigned long* op2 = (unsigned long*)bp;
        *op2 = (*op2) & BITMASK;
    }
    else{
        return;
    }
    printf("After mask: ");
    printByte(bp, asize);
}

void maskB(void* a, int asize){
    printf("initial bits: ");
    char* bp = (char*)a;
    printByte(bp, asize);

    if(asize == 4){
        unsigned int* op1 = (int*)a;
        *op1 = *op1 ^ (~BITMASK);
    }else if(asize == 8){
        unsigned long* op2 = (unsigned long*)a;
        *op2 = *op2 ^ (~BITMASK);
    }

    printf("After mask: ");
    printByte(bp, asize);
}

void maskC(void* a, int asize){
    printf("initial bits: ");
    char* bp = (char*)a;
    printByte(bp, asize);

    if(asize == 4){
        unsigned int* op1 = (int*)a;
        *op1 = *op1 | BITMASK;
    }else if(asize == 8){
        unsigned long* op2 = (unsigned long*)a;
        *op2 = *op2 | BITMASK;
    }

    printf("After mask: ");
    printByte(bp, asize);
}

int main(){
    int x = 0x123456;
    unsigned long y = 0x123456;
    printf("\nx = 0x%X\n\n", x);

    maskA(&x, sizeof(x));
    maskB(&x, sizeof(x));
    maskC(&x, sizeof(x));

    printf("\ny = 0x%X\n\n", y);
    maskA(&y, sizeof(y));
    maskB(&y, sizeof(y));
    maskC(&y, sizeof(y));
}