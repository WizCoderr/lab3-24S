#include <stdio.h>

void printBinary(unsigned int val) {
    for (int i = 31; i >= 0; i--) {
        putchar((val & (1 << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' ');
    }
    putchar('\n');
}

int main() {
    unsigned int A, R, G, B;
    
    printf("Enter A value (0~255): ");
    scanf("%u", &A);
    printf("A: %u binary: ", A);
    printBinary(A);
    
    printf("Enter R value (0~255): ");
    scanf("%u", &R);
    printf("R: %u binary: ", R);
    printBinary(R);
    
    printf("Enter G value (0~255): ");
    scanf("%u", &G);
    printf("G: %u binary: ", G);
    printBinary(G);
    
    printf("Enter B value (0~255): ");
    scanf("%u", &B);
    printf("B: %u binary: ", B);
    printBinary(B);

    unsigned int rgb_pack = (A << 24) | (R << 16) | (G << 8) | B;
    printf("Packed: binary: ");
    printBinary(rgb_pack);
    printf("(%u)\n", rgb_pack);

    printf("Unpacking ......\n");
    unsigned int unpacked_R = (rgb_pack >> 16) & 0xFF;
    unsigned int unpacked_G = (rgb_pack >> 8) & 0xFF;
    unsigned int unpacked_B = rgb_pack & 0xFF;

    printf("R: binary: ");
    printBinary(unpacked_R);
    printf("(%u,%02u,0X%X)\n", unpacked_R, unpacked_R, unpacked_R);

    printf("G: binary: ");
    printBinary(unpacked_G);
    printf("(%u,%02u,0X%X)\n", unpacked_G, unpacked_G, unpacked_G);

    printf("B: binary: ");
    printBinary(unpacked_B);
    printf("(%u,%02u,0X%X)\n", unpacked_B, unpacked_B, unpacked_B);

    return 0;
}