#include <stdio.h>

void printBinary(short int val) {
    for (int i = 15; i >= 0; i--) {
        putchar((val & (1 << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' ');
    }
    putchar('\n');
}

int main() {
    short int flags; 
    char c;
    printf("Enter the flag: ");
    scanf("%hd", &flags);
    getchar();
    printf("Initial flags: ");
    printBinary(flags);
    printf("Enter characters (Ctrl+Z to end input):\n");
    while ((c = getchar()) != -1) {
        if (c >= '0' && c <= '9') {
            flags |= 1 << (c - '0'); 
        }
    }
    printf("Final flags: ");
    printBinary(flags);
    return 0;
}