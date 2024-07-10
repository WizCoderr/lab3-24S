#include <stdio.h>

void printBinary(int val) {
    for (int i = 31; i >= 0; i--) {
        putchar((val & (1 << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' ');
    }
    putchar('\n');
}

int main() {
    int R, G, B;
    const int A = 100;

    while (1) {
        printf("enter R value (0~255): ");
        scanf("%d", &R);
        if (R < 0) break;
        printf("enter G value (0~255): ");
        scanf("%d", &G);
        if (G < 0) break;
        printf("enter B value (0~255): ");
        scanf("%d", &B);
        if (B < 0) break;

        int rgb_pack = (A << 24) | (R << 16) | (G << 8) | B;

        printf("Packed: ");
        printBinary(rgb_pack);

        int unpacked_R = (rgb_pack >> 16) & 0xFF;
        int unpacked_G = (rgb_pack >> 8) & 0xFF;
        int unpacked_B = rgb_pack & 0xFF;

        printf("Unpacked R: %d\n", unpacked_R);
        printf("Unpacked G: %d\n", unpacked_G);
        printf("Unpacked B: %d\n", unpacked_B);
    }

    return 0;
}
